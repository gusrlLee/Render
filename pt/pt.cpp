// Path Tracing

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

#include "common/structs.hpp"
#include "common/utils.hpp"
#include "tiny_obj_loader.h"
#include "glm/glm.hpp"

std::vector<Triangle> g_TriList;

bool TriangleIntersectionTest()
{
    return false;
}

void LoadModel(const char *objFilePath, const char *mtlFilePath)
{
    tinyobj::ObjReaderConfig cfg;
    cfg.mtl_search_path = mtlFilePath;
    cfg.triangulate = true;

    tinyobj::ObjReader reader;
    if (!reader.ParseFromFile(objFilePath, cfg))
    {
        if (!reader.Error().empty())
        {
            std::cerr << "[MESH ERROR] : " << reader.Error();
            exit(1);
        }
    }

    if (!reader.Warning().empty())
        std::clog << "[MESH WARNING] : " << reader.Warning() << std::endl;
    else
        std::clog << "Success to load mesh data!" << std::endl;

    const auto &attrib = reader.GetAttrib();
    const auto &shapes = reader.GetShapes();
    const auto &materials = reader.GetMaterials();

    for (size_t s = 0; s < shapes.size(); s++)
    {
        size_t idxOffset = 0;
        for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++)
        {
            size_t fv = size_t(shapes[s].mesh.num_face_vertices[f]);
            std::vector<Vertex> vbuf;

            for (size_t v = 0; v < fv; v++)
            {
                tinyobj::index_t idx = shapes[s].mesh.indices[idxOffset + v];
                
                // get vertex of triangle
                tinyobj::real_t vx = attrib.vertices[3 * size_t(idx.vertex_index) + 0];
                tinyobj::real_t vy = attrib.vertices[3 * size_t(idx.vertex_index) + 1];
                tinyobj::real_t vz = attrib.vertices[3 * size_t(idx.vertex_index) + 2];

                vbuf.push_back(Vertex{vx, vy, vz});
            }

            // make trianlge 
            g_TriList.push_back(Triangle{vbuf[0], vbuf[1], vbuf[2], shapes[s].mesh.material_ids[f]});
            idxOffset += fv;
            vbuf.clear();
        }
    }
}

int main()
{
    // image width & height setting
    int imgWidth = 720, imgHeight = 480;

    // camera setting for cornell box obj file
    // link : https://www.graphics.cornell.edu/online/box/data.html
    Camera cam = {
        Vector3{278, 273, -800}, /* camera position */
        Vector3{0, 0, 1},        /* direction vector */
        Vector3{0, 1, 0},        /* up vector */
        0.5                      /* focal length */
    };

    // load mesh by using loadModelFunction in utils.hpp
    LoadModel("../../../assets/cornell_box.obj", "../../../assets/");
    std::clog << "[SYSTEM] Triangle list size = " << g_TriList.size() << std::endl;

    // generate ppm file 
    glm::vec3 test = glm::vec3(0.0);
    
    return 0;
}
