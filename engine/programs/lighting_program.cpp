#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "lighting_program.h"
#include "../scene/light.h"

void LightingProgram::ExtractUniforms()
{
    using namespace oglplus;
    auto &prog = *program;
    // assign program
    gPosition.Assign(prog);
    gNormal.Assign(prog);
    gAlbedo.Assign(prog);
    gSpecular.Assign(prog);
    lightTypeCount[0].Assign(prog);
    lightTypeCount[1].Assign(prog);
    lightTypeCount[2].Assign(prog);
    // bind to uniform name
    gPosition.BindTo("gPosition");
    gNormal.BindTo("gNormal");
    gAlbedo.BindTo("gAlbedo");
    gSpecular.BindTo("gSpecular");
    lightTypeCount[0].BindTo("lightTypeCount[0]");
    lightTypeCount[1].BindTo("lightTypeCount[1]");
    lightTypeCount[2].BindTo("lightTypeCount[2]");
    // collections
    directionalLight.resize(Light::DirectionalsLimit);
    pointLight.resize(Light::PointsLimit);

    for (auto i = 0; i < directionalLight.size(); i++)
    {
        auto &light = directionalLight[i];
        auto index = std::to_string(i);
        light.direction.Assign(prog);
        light.ambient.Assign(prog);
        light.diffuse.Assign(prog);
        light.specular.Assign(prog);
        light.direction.BindTo("directionalLight[" + index + "].direction");
        light.ambient.BindTo("directionalLight[" + index + "].ambient");
        light.diffuse.BindTo("directionalLight[" + index + "].diffuse");
        light.specular.BindTo("directionalLight[" + index + "].specular");
    }

    for (auto i = 0; i < pointLight.size(); i++)
    {
        auto &light = pointLight[i];
        auto index = std::to_string(i);
        light.position.Assign(prog);
        light.ambient.Assign(prog);
        light.diffuse.Assign(prog);
        light.specular.Assign(prog);
        light.attenuation.constant.Assign(prog);
        light.attenuation.linear.Assign(prog);
        light.attenuation.quadratic.Assign(prog);
        light.position.BindTo("pointLight[" + index + "].position");
        light.ambient.BindTo("pointLight[" + index + "].ambient");
        light.diffuse.BindTo("pointLight[" + index + "].diffuse");
        light.specular.BindTo("pointLight[" + index + "].specular");
        light.attenuation.constant.BindTo("pointLight[" + index +
                                          "].attenuation.constant");
        light.attenuation.linear.BindTo("pointLight[" + index +
                                        "].attenuation.linear");
        light.attenuation.quadratic.BindTo("pointLight[" + index +
                                           "].attenuation.quadratic");
    }
}

LightingProgram::~LightingProgram()
{}
