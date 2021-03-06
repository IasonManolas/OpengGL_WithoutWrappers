#ifndef CGALTYPEDEFS_H
#define CGALTYPEDEFS_H

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/extract_mean_curvature_flow_skeleton.h>
// using Kernel = CGAL::Exact_predicates_inexact_constructions_kernel;
using Kernel = CGAL::Simple_cartesian<double>;
using CGALSurfaceMesh = CGAL::Surface_mesh<Kernel::Point_3>;

using Ray = Kernel::Ray_3;
using Point = Kernel::Point_3;
using v_index = CGALSurfaceMesh::vertex_index;
// segment mesh
using face_descriptor = boost::graph_traits<CGALSurfaceMesh>::face_descriptor;
using Facet_double_map = CGALSurfaceMesh::Property_map<face_descriptor, double>;
using Facet_int_map =
    CGALSurfaceMesh::Property_map<face_descriptor, std::size_t>;

// intersects
#include <CGAL/AABB_face_graph_triangle_primitive.h>
#include <CGAL/AABB_traits.h>
#include <CGAL/AABB_tree.h>
using Primitive = CGAL::AABB_face_graph_triangle_primitive<CGALSurfaceMesh>;
using Traits = CGAL::AABB_traits<Kernel, Primitive>;
using Tree = CGAL::AABB_tree<Traits>;
using Ray_intersection =
    boost::optional<Tree::Intersection_and_primitive_id<Kernel::Ray_3>::Type>;
#include <glm/vec3.hpp>
struct MyVertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec3 Color{glm::vec3(0.0f, 0.0f, 0.0f)};
};
using Input_vertex_descriptor = size_t;
using Point3D = CGALSurfaceMesh::Point;
struct Vmap {
	Point3D point;
	std::vector<Input_vertex_descriptor>
	    collapsed_vertices;  // This might not be needed
	std::vector<Point3D> collapsed_positions;
};
using SkeletonGraph =
    boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, Vmap>;
#endif  // CGALTYPEDEFS_H
