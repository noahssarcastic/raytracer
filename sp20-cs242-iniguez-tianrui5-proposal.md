# Overview
## Motivation
For this project I will be implementing a ray-tracer from scratch. Since coming 
to this school I have been interested in computer graphics. I took CS418 years 
ago but was never able to fit CS419 into my schedule. I bought the text book 
years ago to read in my own time but have never had the time to implement the 
theory. I see this project as the perfect time to finally pursue this passion 
project. Though I won't be able to implement all the features in the course or 
in the textbook, I hope to have the basic requirements of a ray-tracer and a 
few extra fun features at the end of this three weeks.

## Technology and Style
For this project I will be using C++ and be following the 
[Google C++ styleguide.](https://google.github.io/styleguide/cppguide.html).
I will also need to use an external open-source bitmap library since 
implementing the bitmap image format is out of the scope of this project. The 
code will be broken up into two main libraries and a command-line-interface. 
The two libraries will be a geometry library and an effects library. Both 
libraries will be implemented follwong OOP best practices.

## Features
### Geometries
* OBJ or PLY format support
* Ray-object intersection support for:
    * Planes
    * Spheres
    * Triangles
* Movable camera supporting:
    * Orthographic projection
    * Perspective projection

### Lighting
* Support for point lights
* Support for area lights

### Shading
* Support for shadows
* Support for diffuse and specular reflection (Phong model)

### Misc.
* Rendering a mirror-like object
* Rendering a transparent object
* Calculation Optimizations
* Multi-jittered sampling


# Week 1
## Functional Requirements (15 points)
* OBJ or PLY format support (1 point)
* Ray-object intersection support (9 points)
    * Planes (3 points)
        * Basic implementation (1 point)
        * Implement operator overrides (1 point)
        * Supports color (1 point)
    * Spheres (3 points)
        * Basic implementation (1 point)
        * Implement operator overrides (1 point)
        * Supports color (1 point)
    * Triangles (3 points)
        * Basic implementation (1 point)
        * Implement operator overrides (1 point)
        * Supports color (1 point)
* Movable camera (5 points)
    * Orthographic projection (3 points)
        * Basic implementation (1 point)
        * Implement operator overrides (1 point)
        * Support for projection options (1 point)
    * Perspective projection (2 points)
        * Basic implementation (1 point)
        * Implement operator overrides (1 point)

## Testing Requirements (10 points)
* Library Testing (8 points)
    * Good code coverage (2 points)
        * 1 point for 70%
        * 2 points for 90%
    * Tests camera to object raycasts for planes (2 points)
        * Orthographic (1 point)
        * Perspective (1 point)
    * Tests camera to object raycasts for spheres (2 points)
        * Orthographic (1 point)
        * Perspective (1 point)
    * Tests camera to object raycasts for triangles (2 points)
        * Orthographic (1 point)
        * Perspective (1 point)
* Manual Testing (2 points)
    * Test plan includes tests for creating a scene (1 point)
    * Test plan includes tests for using cli (1 point)

# Week 2
## Functional Requirements (15 points)
* Support for point lights (3 points)
    * Point lights implemented (1 point)
    * Implement operator overrides (1 point)
    * Support for color (1 point)
* Support for area lights (3 points)
    * area lights implemented (1 point)
    * Implement operator overrides (1 point)
    * Support for color (1 point)
* Support for shadows (3 points)
    * Hard shadows implemented (1 point)
    * Implement operator overrides (1 point)
    * Soft shadows implemented (1 point)
* Support reflection (6 points)
    * Diffuse reflection (2 points)
        * Diffuse reflection implemented (1 point)
        * Implement operator overrides (1 point)
    * Specular reflection (4 points)
        * Specular reflection implemented (1 point)
        * Implement operator overrides (1 point)
        * Support for diffuse and specular together (1 point)
        * Specular reflection is adjustable (1 point)

## Testing Requirements (10 points)
* Good code coverage (2 points)
    * 1 point for 70%
    * 2 points for 90%
* Tests point light to object raycasts (2 points)
    * 0 points for no tests
    * 1 point for basic tests
    * 2 points for edge case testing
* Tests area light to object raycasts (2 points)
    * 0 points for no tests
    * 1 point for basic tests
    * 2 points for edge case testing
* Tests shadow caluclations (2 points)
    * 0 points for no tests
    * 1 point for basic tests
    * 2 points for edge case testing
* Tests reflection calculations (2 points)
    * 0 points for no tests
    * 1 point for basic tests
    * 2 points for edge case testing

# Week 3
## Functional Requirements (15 points)
* Rendering a mirror-like object (5 points)
    * Basic implementation (2 point)
    * Implement operator overrides (1 point)
    * Adjustable reflectance (2 points)
* Rendering a transparent object (5 points)
    * Basic implementation (2 point)
    * Implement operator overrides (1 point)
    * Adjustable opacity (2 points)
* Calculation Optimizations (4 points)
    * 1 point for implementation of a data structure for intersection testing
    * 2 points for preformance increase of at least 20%
    * 3 points for preformance increase of at least 50%
    * 4 points for preformance increase of at least 100%
* Multi-jittered sampling (1 point)

## Testing Requirements (10 points)
* Update manual test plan (4 points)
    * 2 point for updates for week 2 or 3 features
    * 4 points for updates for both weeks 2 and 3
* Library Testing (6 points)
    * Good code coverage (2 points)
        * 1 point for 70%
        * 2 points for 90%
    * Tests for mirror surface calculations (2 points)
        * 0 points for no tests
        * 1 point for basic tests
        * 2 points for edge case testing
    * Tests for transparent surface calculations (2 points)
        * 0 points for no tests
        * 1 point for basic tests
        * 2 points for edge case testing
