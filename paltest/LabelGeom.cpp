#include "stdafx.h"
#include "LabelGeom.h"


LabelGeom::LabelGeom(GEOSGeometry* geom) : m_geosgeom(geom)
{
	
}


LabelGeom::~LabelGeom()
{
}

GEOSGeometry* LabelGeom::getGeosGeometry()
{
	return m_geosgeom;
}

void LabelGeom::releaseGeosGeometry(GEOSGeometry *the_geom)
{
	;
}
