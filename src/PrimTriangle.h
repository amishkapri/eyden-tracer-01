// Triangle Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "IPrim.h"
#include "ray.h"

// ================================ Triangle Primitive Class ================================
/**
 * @brief Triangle Geometrical Primitive class
 * @ingroup modulePrimitive
 * @author Sergey G. Kosov, sergey.kosov@project-10.de
 */
class CPrimTriangle : public IPrim
{
public:
	/**
	 * @brief Constructor
	 * @param a Position of the first vertex
	 * @param b Position of the second vertex
	 * @param c Position of the third vertex
	 */
	CPrimTriangle(const Vec3f& a, const Vec3f& b, const Vec3f& c)
		: IPrim()
		, m_a(a)
		, m_b(b)
		, m_c(c)
  	{}
	virtual ~CPrimTriangle(void) = default;
	
	virtual bool intersect(Ray& ray) const override
	{
		Vec3f n_ab = (m_b - ray.org).cross(m_a - ray.org);
		Vec3f n_bc = (m_c - ray.org).cross(m_b - ray.org);
		Vec3f n_ca = (m_a - ray.org).cross(m_c - ray.org);

		float area = n_ab.dot(ray.dir) + n_bc.dot(ray.dir) + n_ca.dot(ray.dir);
		float l1 = n_ab.dot(ray.dir) / area;
		float l2 = n_bc.dot(ray.dir) / area;
		float l3 = n_ca.dot(ray.dir) / area;

		if (l1 < 0 || l2 < 0 || l3 < 0){
			return false;
		}
		
		Vec3f p = l1 * m_a + l2 * m_b + l3 * m_c;
		
		float t = p[0] / ray.dir[0];
		if (t < Epsilon || t > ray.t){
			return false;
		}

		ray.t = t;

		return true;
	}

	
private:
	Vec3f m_a;		///< Position of the first vertex
	Vec3f m_b;		///< Position of the second vertex
	Vec3f m_c;		///< Position of the third vertex
};
