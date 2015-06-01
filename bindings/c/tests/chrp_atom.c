#include "chemharp.h"

// Force NDEBUG to be undefined
#undef NDEBUG
#include <assert.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    CHRP_ATOM* a = chrp_atom("He");

    float mass=0, charge=0;
    assert(!chrp_atom_mass(a, &mass));
    assert(fabs(mass - 4.002602) < 1e-6);
    assert(!chrp_atom_charge(a, &charge));
    assert(fabs(charge) < 1e-6);

    char name[32];
    assert(!chrp_atom_name(a, name, sizeof(a)/sizeof(char)));
    assert(strcmp(name, "He") == 0);

    assert(!chrp_atom_set_mass(a, 678));
    assert(!chrp_atom_mass(a, &mass));
    assert(fabs(mass - 678) < 1e-6);

    assert(!chrp_atom_set_charge(a, -1.5));
    assert(!chrp_atom_charge(a, &charge));
    assert(fabs(charge + 1.5) < 1e-6);

    assert(!chrp_atom_set_name(a, "Zn"));
    assert(!chrp_atom_name(a, name, sizeof(a)/sizeof(char)));
    assert(strcmp(name, "Zn") == 0);

    assert(!chrp_atom_full_name(a, name, sizeof(a)/sizeof(char)));
    assert(strcmp(name, "Zinc") == 0);

    double radius=0;
    assert(!chrp_atom_vdw_radius(a, &radius));
    assert(fabs(radius - 2.1) < 1e-6);
    assert(!chrp_atom_covalent_radius(a, &radius));
    assert(fabs(radius - 1.31) < 1e-6);

    int number = 0;
    assert(!chrp_atom_atomic_number(a, &number));
    assert(number == 30);

    return EXIT_SUCCESS;
}

/* TODO: Missing functions:
 * chrp_atom_from_frame
 * chrp_atom_from_topology
 */
