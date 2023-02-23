#include <libdecomputil.h>
#include <stdio.h>


int main(int argc, char **argv) {

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

  int npoly = seedDecomp2d_polyhedron(
		  posx, posy,
		  nobs, obs_x, obs_y,
		  bbox_x, bbox_y,
		  dilation, max_poly,
		  poly_px, poly_py, poly_nx, poly_ny);

  printf("N poly: %d\n", npoly);

  return 0;
}
