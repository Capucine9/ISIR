#ifndef __RT_ISICG_PLANE__
#define __RT_ISICG_PLANE__

#include "base_object.hpp"
#include "geometry/PlaneGeometry.hpp"

namespace RT_ISICG
{
	class Plane : public BaseObject
	{
	  public:
		Plane()		  = delete;
		virtual ~Plane() = default;

		Plane( const std::string & p_name, const Vec3f & p_point, const Vec3f & p_normale )
			: BaseObject( p_name ), _geometry( p_point, p_normale )
		{
		}

		bool intersect( const Ray & p_ray, const float p_tMin, const float p_tMax, HitRecord & p_hitRecord ) const;

		// TP2_Exo 5_1 :
		bool intersectAny( const Ray & p_ray, const float p_tMin, const float p_tMax ) const; 

	  private:
		PlaneGeometry _geometry;
	};
} // namespace RT_ISICG
#endif // __RT_ISICG_PLANE__

