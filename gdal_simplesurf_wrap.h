#include "gdal_simplesurf.h"


// #ifdef __cplusplus
#ifdef XYZRWEE

class GDALFeaturePoint
{
public:
    /**
     * Standard constructor. Initializes all parameters with negative numbers
     * and allocates memory for descriptor.
     */
    GDALFeaturePoint();

    /**
     * Copy constructor
     * @param fp Copied instance of GDALFeaturePoint class
     */
    GDALFeaturePoint(const GDALFeaturePoint& fp);

    /**
     * Create instance of GDALFeaturePoint class
     *
     * @param nX X-coordinate (pixel)
     * @param nY Y-coordinate (line)
     * @param nScale Scale which contains this point (2, 4, 8, 16 and so on)
     * @param nRadius Half of the side of descriptor area
     * @param nSign Sign of Hessian determinant for this point
     *
     * @note This constructor normally is invoked by SURF-based algorithm,
     * which provides all necessary parameters.
     */
    GDALFeaturePoint(int nX, int nY, int nScale, int nRadius, int nSign);
    virtual ~GDALFeaturePoint();

    GDALFeaturePoint& operator=(const GDALFeaturePoint& point);

    /**
     * Provide access to point's descriptor.
     *
     * @param nIndex Position of descriptor's value.
     * nIndex should be within range from 0 to DESC_SIZE (in current version - 64)
     *
     * @return Reference to value of descriptor in 'nIndex' position.
     * If index is out of range then behaviour is undefined.
     */
    double& operator[](int nIndex);

    // Descriptor length
    static const int DESC_SIZE = 64;

    /**
     * Fetch X-coordinate (pixel) of point
     *
     * @return X-coordinate in pixels
     */
    int GetX();

    /**
     * Set X coordinate of point
     *
     * @param nX X coordinate in pixels
     */
    void SetX(int nX);

    /**
     * Fetch Y-coordinate (line) of point.
     *
     * @return Y-coordinate in pixels.
     */
    int  GetY();

    /**
     * Set Y coordinate of point.
     *
     * @param nY Y coordinate in pixels.
     */
    void SetY(int nY);

    /**
     * Fetch scale of point.
     *
     * @return Scale for this point.
     */
    int  GetScale();

    /**
     * Set scale of point.
     *
     * @param nScale Scale for this point.
     */
    void SetScale(int nScale);

    /**
     * Fetch radius of point.
     *
     * @return Radius for this point.
     */
    int  GetRadius();

    /**
     * Set radius of point.
     *
     * @param nRadius Radius for this point.
     */
    void SetRadius(int nRadius);

    /**
     * Fetch sign of Hessian determinant of point.
     *
     * @return Sign for this point.
     */
    int  GetSign();

    /**
     * Set sign of point.
     *
     * @param nSign Sign of Hessian determinant for this point.
     */
    void SetSign(int nSign);

private:
    // Coordinates of point in image
    int nX;
    int nY;
    // --------------------
    int nScale;
    int nRadius;
    int nSign;
    // Descriptor array
    double *padfDescriptor;
};

#else
	  typedef  struct GDALFeaturePoint GDALFeaturePoint;
#endif

#ifdef __cplusplus
extern "C" {
#endif

GDALFeaturePoint*  getGDALFeaturePoint(GDALFeaturePoint a);
void  destroyGDALFeaturePoint(GDALFeaturePoint *foo);
GDALFeaturePoint*  GDALFeaturePoint_GetRadius(GDALFeaturePoint *foo, int *val);
GDALFeaturePoint*  GDALFeaturePoint_SetRadius(GDALFeaturePoint *foo, int val);

#ifdef __cplusplus
}
#endif