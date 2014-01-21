========================================================================
    STATIC LIBRARY : BasicShapes Project Overview
========================================================================

This file contains a summary of what you will find in each of the files that
make up your BasicShapes application.


BasicShapes.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

BasicShapes.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).


/////////////////////////////////////////////////////////////////////////////

Shape.h
    The base class for the shapes.

PointProtocol.h
    A protocol (interface) that the shapes follow when doing point-based calculations. 

pUtils.h
    The under-the-hood class for Point based calculations.

Point.cpp
    The under-the-hood class definition for Point based calculations.

Circle.h, Circle.cpp
    A Circle shape.

Rectangle.h, Rectangle.cpp
    A Rectangle shape.

Ring.h, Ring.cpp
    A Ring shape that's based on the Circle shape.

/////////////////////////////////////////////////////////////////////////////