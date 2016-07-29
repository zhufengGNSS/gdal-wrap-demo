#include "gdal_simplesurf_wrap.h"

#ifdef __cplusplus
extern "C" {
#endif

GDALFeaturePoint*  getGDALFeaturePoint(GDALFeaturePoint a){
	return (GDALFeaturePoint*) new GDALFeaturePoint(a);
}
void  destroyGDALFeaturePoint(GDALFeaturePoint *foo){
	delete foo;
	foo = NULL;
}
GDALFeaturePoint*  GDALFeaturePoint_GetRadius(GDALFeaturePoint *foo, int * val){
	*val = foo->GetRadius();
	return foo;
}
GDALFeaturePoint*  GDALFeaturePoint_SetRadius(GDALFeaturePoint *foo, int val){
	foo->SetRadius(val);
	return foo;	
}

#ifdef __cplusplus
}
#endif