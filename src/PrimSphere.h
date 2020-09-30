// Sphere Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "IPrim.h"
#include "ray.h"

// ================================ Sphere Primitive Class ================================
/**
 * @brief Sphere Geaometrical Primitive class
 * @ingroup modulePrimitive
 * @author Sergey G. Kosov, sergey.kosov@project-10.de
 */
class CPrimSphere : public IPrim
{
public:
	/**
	 * @brief Constructor
		 * @param origin Position of the center of the sphere
		 * @param radius Radius of the sphere
	 */
	CPrimSphere(Vec3f origin, float radius)
		: IPrim()
		, m_origin(origin)
		, m_radius(radius)
	{}
	virtual ~CPrimSphere(void) = default;

	virtual bool intersect(Ray &ray) const override
	{
		float a = ray.dir.dot(ray.dir);
		float b = 2 * ray.dir.dot(ray.org - m_center);
		float c = (ray.org - m_center).dot(ray.org - m_center) - m_radius * m_radius;
		float check = b * b - (4 * a * c);
		if (check < 0){
			return false;
		} 
		float t = ((-b) + sqrt(check)) / a;

		if (t < Epsilon || t > ray.t){
			return false;
		}
		ray.t = t;
		return true;
	}
	
	
private:
	Vec3f m_origin;	///< Position of the center of the sphere
	float m_radius;	///< Radius of the sphere
};

