// Chemfiles, a modern library for chemistry file reading and writing
// Copyright (C) Guillaume Fraux and contributors -- BSD license
#include <catch.hpp>
#include <chemfiles.hpp>
using namespace chemfiles;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#undef assert
#define assert CHECK

TEST_CASE() {
    // [example]
    auto frame = Frame();
    frame.add_atom(Atom(""), {1.0, 0.0, 0.0});
    frame.add_atom(Atom(""), {0.0, 0.0, 0.0});
    frame.add_atom(Atom(""), {0.0, 1.0, 0.0});
    frame.add_atom(Atom(""), {0.0, 1.0, 1.0});

    assert(fabs(frame.dihedral(0, 1, 2, 3) - M_PI / 2) < 1e-12);
    // [example]
}
