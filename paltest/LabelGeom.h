#pragma once

#include <pal/palgeometry.h>
#include <geos_c.h>

class LabelGeom : public pal::PalGeometry
{
private:

	GEOSGeometry* m_geosgeom;

public:
	LabelGeom(GEOSGeometry* geom);
	~LabelGeom();

public:

	GEOSGeometry* getGeosGeometry();
	void releaseGeosGeometry(GEOSGeometry *the_geom);
};

