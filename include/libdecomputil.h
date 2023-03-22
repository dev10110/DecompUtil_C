
#ifndef __LIBDECOMPUTIL
#define __LIBDECOMPUTIL

#ifdef __cplusplus
extern "C" {
#endif

int seedDecomp2d_polyhedron( float posx, float posy, 
    int nobs, float* obsx, float* obsy,
    float local_bbox_x, float local_bbox_y,
    float dilation_radius,
    int max_npoly,
    float* poly_px, float* poly_py, float* poly_nx, float* poly_ny
);

int seedDecomp3d_polyhedron( float posx, float posy, float posz, 
    int nobs, float* obsx, float* obsy,float* obsz,
    float local_bbox_x, float local_bbox_y, float local_bbox_z,
    float dilation_radius,
    int max_npoly,
    float* poly_px, float* poly_py, float* poly_pz,
    float* poly_nx, float* poly_ny, float* poly_nz
);

#ifdef __cplusplus
}
#endif

#endif // __LIBDECOMPUTIL
