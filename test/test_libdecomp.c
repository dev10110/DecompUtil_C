#include <libdecomputil.h>
#include <stdio.h>


void test2D() 
{
  float posx = 0.0;
  float posy = 0.0;

  float obs_x[] = {-0.2, 1, 0.8, -0.5};
  float obs_y[] = {1.5, 0, -1, -0.5};

  long long nobs = 4;

  const int max_poly = 10;
  float poly_px[max_poly];
  float poly_py[max_poly];
  float poly_nx[max_poly];
  float poly_ny[max_poly];

  float bbox_x = 2.0;
  float bbox_y = 2.0;

  float dilation = 0.1;

  unsigned long long npoly = seedDecomp2d_polyhedron(
		  posx, posy,
		  nobs, obs_x, obs_y,
		  bbox_x, bbox_y,
		  dilation, max_poly,
		  poly_px, poly_py, poly_nx, poly_ny);

  printf("N poly: %lld\n", npoly);
  if (npoly==8){
	  printf("SUCCESS!\n");
  } else {
	  printf("Failed! Should be 8\n");
  }

}

void test3D() 
{
  float posx = 0.0;
  float posy = 0.0;
  float posz = 0.0;

  float obs_x[] = {-0.2, 1, 0.8, -0.5};
  float obs_y[] = {1.5, 0, -1, -0.5};
  float obs_z[] = {1.0, -1.0, 1.0, -1.0};

  long long nobs = 4;

  const int max_poly = 20;
  float poly_px[max_poly];
  float poly_py[max_poly];
  float poly_pz[max_poly];
  float poly_nx[max_poly];
  float poly_ny[max_poly];
  float poly_nz[max_poly];

  float bbox_x = 2.0;
  float bbox_y = 2.0;
  float bbox_z = 2.0;

  float dilation = 0.1;

  unsigned long long npoly = seedDecomp3d_polyhedron(
		  posx, posy, posz,
		  nobs, obs_x, obs_y, obs_z,
		  bbox_x, bbox_y, bbox_z,
		  dilation, max_poly,
		  poly_px, poly_py, poly_pz, poly_nx, poly_ny, poly_nz);

  printf("N poly: %lld\n", npoly);
  if (npoly==10){
          printf("SUCCESS!\n");
  } else {
          printf("Failed! Should be 10\n");
  }

}

int main(int argc, char **argv) {

  test2D();

  test3D();

  return 0;
}
