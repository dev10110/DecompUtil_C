

#include <decomp_util/seed_decomp.h>
#include <decomp_geometry/geometric_utils.h>

#include <libdecomputil.h>

extern "C" {

int seedDecomp2d_polyhedron( float posx, float posy, 
    long long nobs, float* obsx, float* obsy,
    float local_bbox_x, float local_bbox_y,
    float dilation_radius, 
    long long max_npoly,
    float* poly_px, float* poly_py, float* poly_nx, float* poly_ny
    )
{

  // Obstacles
  vec_Vec2f obs;
  for (std::size_t i=0; i < (std::size_t)nobs; i++){
    obs.push_back(Vec2f(obsx[i], obsy[i]));
  }

  // Seed
  const Vec2f pos(posx, posy);

  // Run SeedDecomp2D
  SeedDecomp2D decomp(pos);
  decomp.set_obs(obs);
  decomp.set_local_bbox(Vec2f(local_bbox_x, local_bbox_y));
  decomp.dilate(dilation_radius);

  // extract results
  const auto poly = decomp.get_polyhedron();
  const auto hyperplanes = poly.hyperplanes();

  for (std::size_t i=0; i < hyperplanes.size() && i < (std::size_t)max_npoly; i++){
    const auto p = hyperplanes[i].p_;
    const auto n = hyperplanes[i].n_;
    poly_px[i] = p(0);
    poly_py[i] = p(1);
    poly_nx[i] = n(0);
    poly_ny[i] = n(1);
  }

  return hyperplanes.size();

}

int seedDecomp3d_polyhedron( float posx, float posy, float posz,
    long long nobs, float* obsx, float* obsy, float* obsz,
    float local_bbox_x, float local_bbox_y, float local_bbox_z,
    float dilation_radius, 
    long long max_npoly, 
    float* poly_px, float* poly_py, float* poly_pz, 
    float* poly_nx, float* poly_ny, float* poly_nz
    )
{

  // Obstacles
  vec_Vec3f obs;
  for (std::size_t i=0; i < (std::size_t)nobs; i++){
    obs.push_back(Vec3f(obsx[i], obsy[i], obsz[i]));
  }

  // Seed
  const Vec3f pos(posx, posy, posz);

  // Run SeedDecomp3D
  SeedDecomp3D decomp(pos);
  decomp.set_obs(obs);
  decomp.set_local_bbox(Vec3f(local_bbox_x, local_bbox_y, local_bbox_z));
  decomp.dilate(dilation_radius);

  // extract results
  const auto poly = decomp.get_polyhedron();
  const auto hyperplanes = poly.hyperplanes();

  for (std::size_t i=0; i < hyperplanes.size() && i < (std::size_t)max_npoly; i++){
    const auto p = hyperplanes[i].p_;
    const auto n = hyperplanes[i].n_;
    poly_px[i] = p(0);
    poly_py[i] = p(1);
    poly_pz[i] = p(2);
    poly_nx[i] = n(0);
    poly_ny[i] = n(1);
    poly_nz[i] = n(2);
  }

  return hyperplanes.size();

}

}


