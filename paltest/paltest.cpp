// paltest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <pal/layer.h>
#include <geos_c.h>
#include <stdlib.h> 
#include <time.h> 

#include "LabelGeom.h"
#include <vector>

#define MAX 1000

int main()
{
	pal::Pal *pal = new pal::Pal();

	
	int np = 100;
	pal->setPointP(np);
	pal->setDpi(96);
	pal->setSearch(pal::POPMUSIC_CHAIN);
	pal->setMapUnit(pal::PIXEL);
	
	pal::Layer * layer = pal->addLayer("layername", -1, -1, pal::P_POINT, pal::PIXEL, 0.5, false, true, true);
	
	std::vector<LabelGeom*> Geoms;

	GEOSContextHandle_t ctx = GEOS_init_r();
	srand((unsigned)time(NULL));
	int it = 1;
	for (size_t i = 0; i < np; i++)
	{
		GEOSCoordSequence *crdseq = GEOSCoordSeq_create_r(ctx, 1, 2);
		GEOSCoordSeq_setX_r(ctx, crdseq, 0, rand() % MAX);
		GEOSCoordSeq_setY_r(ctx, crdseq, 0, rand() % MAX);
		GEOSGeometry* p = GEOSGeom_createPoint_r(ctx, crdseq);
		LabelGeom* lg = new LabelGeom(p);
		Geoms.push_back(lg);
		char *gid = new char[int(ceil(log(it))) + 2];
		sprintf(gid, "%d", it);
		it++;
		layer->registerFeature(gid, lg, 20, 10);
		delete[] gid;
	}
	

	pal::PalStat *stats;

	double bbox[4] = { 0, 0, 1000, 1000 };
	double scale = 1.0;

	std::list<pal::Label*> * labels = pal->labeller(scale, bbox, &stats, true);

	delete pal;
	for (size_t i = 0; i < Geoms.size(); i++)
	{
		GEOSGeom_destroy_r(ctx,Geoms[i]->getGeosGeometry());
		delete Geoms[i];
	}
	Geoms.clear();

	while (labels->size() > 0) {
		pal::Label* lb = labels->front();
		delete lb;
		labels->pop_front();
	}

	delete stats;

	delete labels;
    return 0;
}

