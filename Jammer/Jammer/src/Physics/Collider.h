#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
namespace jam {
	namespace phys {
		typedef sf::Rect<float> AABB;
		typedef sf::Vector2f v2;
		struct bArea;
		struct bCirc;
		struct bRect;
		struct bCvx;
		enum Shape {
			crcl = 1,
			cvx = 2,
			tri = 3,
			rect = 4,
		};
		struct bArea {
			sf::Transform tMat;
			v2 center;
			bool isSolid;
			AABB box;
			bArea(v2 center, bool isSolid) : center(center), isSolid(isSolid) {}
			virtual bool containsPoint(v2 point);
			virtual bool intersects(bCirc);
			virtual bool intersects(bRect);
			virtual bool intersects(bCvx);
			bool AABBoverlap(AABB other) {
				return box.intersects(other);
			}
			bool AABBoverlap(AABB other, AABB& overlap) {
				return box.intersects(other, overlap);
			}
			virtual Shape getType();

		};
		struct bCirc : public bArea{
			float radius;

			bCirc(v2 center, float radius, bool isSolid) : bArea(center, isSolid), radius(radius) {}

			bool containsPoint(v2 point) {
				v2 tv = center - point;
				float dist2 = pow(tv.x, 2) + pow(tv.y, 2);
				return pow(radius, 2.0f) <= dist2;
			}

			bool intersects(bCirc obj) {
				v2 tv = (center - obj.center);
				float dist2 = pow(tv.x, 2) + pow(tv.y, 2);
				return pow(radius + obj.radius, 2.0f) <= dist2;
				
			}

			bool intersects(bRect obj) {

			}

			bool intersects(bCvx obj) {
				return obj.intersects(*this);
			}

			Shape getType() {
				return Shape::crcl;
			}

		};
		struct bRect : public bArea {
			v2 size;

			bRect(AABB rec, bool isSolid) : size(v2(rec.width, rec.height)), bArea(v2(rec.left + size.x / 2, rec.top + size.y / 2), isSolid) { box = rec; }
			bRect(v2 center, v2 size, bool isSolid) : size(size), bArea(center, isSolid) { box = AABB(v2(center.x - size.x / 2, center.y - size.y / 2), size); }
			bool containsPoint(v2 point) {

			}

			bool intersects(bCirc obj) {

			}

			bool intersects(bRect obj) {

			}

			bool intersects(bCvx obj) {
				return obj.intersects(*this);
			}

			Shape getType() {
				return Shape::rect;
			}

		};
		struct bCvx : public bArea {
			int vertCt;
			std::vector<v2> verts;

			bCvx(std::vector<v2> verts, int numVerts, bool isSolid) : verts(verts), vertCt(numVerts), bArea(computeCenter(verts, numVerts), isSolid) { }

			//TEST THIS NOOOOOOOOOOOOOOOOOOO U FUCKING LOSER IDIOT
			v2 computeCenter(const std::vector<v2>& verts, int nVerts )
			{
				
				float cx = 0, cy = 0, d = 0, temp = 0;
				unsigned int j = 0;

				for (unsigned int i = 0; i < nVerts; i++)
				{
					
					if (i + 1 == nVerts)
						j = 0;
					else
						j = i + 1;

					
					temp = verts[i].x * verts[j].y - verts[j].x * verts[i].y;
					d += temp;

					cx += (verts[i].x + verts[j].x) * temp;
					cy += (verts[i].y + verts[j].y) * temp;
				}
				cx /= 3 * d;
				cy /= 3 * d;
				return v2(cx, cy);
			}

			bool containsPoint(v2 point) {

			}

			bool intersects(bCirc obj) {

			}

			bool intersects(bRect obj) {

			}

			bool intersects(bCvx obj) {

			}
			Shape getType() {
				if (vertCt == 3)
					return Shape::tri;

				return Shape::crcl;
			}

		};
	}
}