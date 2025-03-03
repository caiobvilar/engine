from conan import ConanFile
from conan.tools.cmake import cmake_layout


class ExampleRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("entt/3.14.0")
        self.requires("sdl/2.30.9")
        self.requires("spdlog/1.15.1")
        self.requires("glm/1.0.1")

    def layout(self):
        cmake_layout(self)