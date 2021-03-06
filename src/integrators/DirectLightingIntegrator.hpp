#ifndef __RT_ISICG_DIRECT_LIGHT_LIGHTING_INTEGRATOR__
#define __RT_ISICG_DIRECT_LIGHT_LIGHTING_INTEGRATOR__

#include "base_integrator.hpp"
#include "defines.hpp"

namespace RT_ISICG
{
	class DirectLightingIntegrator : public BaseIntegrator
	{
	  public:
		DirectLightingIntegrator() : BaseIntegrator() {}
		virtual ~DirectLightingIntegrator() = default;

		Vec3f Li( const Scene & p_scene,
						  const Ray &	p_ray,
						  const float	p_tMin,
						  const float	p_tMax ) const override;

		const IntegratorType getType() const override { return IntegratorType::DIRECT_LIGHT; }

	  private:
		Vec3f _directLighting( const Scene &   p_scene,
							   const Ray & p_ray,
							   HitRecord &	 hitRecord,
							   const float	 p_tMin,
							   const float	 p_tMax ) const;

	  protected:
		int _nbLightSamples = 32;
			 
	};

} // namespace RT_ISICG

#endif // __RT_ISICG_DIRECT_LIGHT_LIGHTING_INTEGRATOR__
