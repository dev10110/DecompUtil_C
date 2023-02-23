
#ifndef __WRAPPER_DECOMP
#define __WRAPPER_DECOMP

#ifdef __cplusplus
extern "C" {
#endif

int twice(int x);

int seedDecomp2d_polyhedron( float posx, float posy, 
    long long nobs, float* obsx, float* obsy,
    float local_bbox_x, float local_bbox_y,
    float dilation_radius,
    long long max_npoly,
    float* poly_px, float* poly_py, float* poly_nx, float* poly_ny
);

#ifdef __cplusplus
}
#endif

#endif // __WRAPPER_DECOMP
