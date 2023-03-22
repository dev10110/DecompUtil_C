
#ifndef __LIBDECOMPUTIL
#define __LIBDECOMPUTIL

#ifdef __cplusplus
extern "C" {
#endif

unsigned long long seedDecomp2d_polyhedron( float posx, float posy, 
    unsigned long long nobs, float* obsx, float* obsy,
    float local_bbox_x, float local_bbox_y,
    float dilation_radius,
    unsigned long long max_npoly,
    float* poly_px, float* poly_py, float* poly_nx, float* poly_ny
);

unsigned long long seedDecomp3d_polyhedron( float posx, float posy, float posz, 
    unsigned long long nobs, float* obsx, float* obsy,float* obsz,
    float local_bbox_x, float local_bbox_y, float local_bbox_z,
    float dilation_radius,
    unsigned long long max_npoly,
    float* poly_px, float* poly_py, float* poly_pz,
    float* poly_nx, float* poly_ny, float* poly_nz
);

#ifdef __cplusplus
}
#endif

#endif // __LIBDECOMPUTIL
