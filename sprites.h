#pragma once
#include <Gamebuino-Meta.h>

const Color PALETTE[] = {

    (Color) 0x0000, // 0x0
    (Color) 0x18c3, // 0x1
    (Color) 0x3186, // 0x2
    (Color) 0x4228, // 0x3
    (Color) 0x632c, // 0x4
    (Color) 0xad55, // 0x5
    (Color) 0xee2f, // 0x6
    (Color) 0xff36, // 0x7
    (Color) 0x0862, // 0x8
    (Color) 0x10e4, // 0x9
    (Color) 0x1926, // 0xa
    (Color) 0x6217, // 0xb
    (Color) 0x7afa, // 0xc
    (Color) 0xb4df, // 0xd
    (Color) 0xf81f, // 0xe
    (Color) 0x0000  // 0xf

};

const uint16_t PLAYER_DATA[] = {

    // metadata

    6,      // frame width
    6,      // frame height
    6,      // frames
    6,      // frame loop
    0xf81f, // transparent color
    0,      // 16-bits color mode

    // colormap

    // frame 1/6
    0xf81f, 0xf6e5, 0xf6e5, 0xf6e5, 0xf6e5, 0xf81f,
    0xf81f, 0x2bd7, 0xfdcd, 0x2bd7, 0xfdcd, 0xf81f,
    0xf81f, 0xfdcd, 0xfdcd, 0xfdcd, 0xfdcd, 0xf81f,
    0xfdcd, 0xa324, 0xa324, 0xb841, 0xb841, 0xb841,
    0xf81f, 0xa324, 0xa324, 0xa324, 0xa324, 0xfdcd,
    0xf81f, 0xc300, 0xf81f, 0xb841, 0xc300, 0xb841,

    // frame 2/6
    0xf81f, 0xf6e5, 0xf6e5, 0xf6e5, 0xf6e5, 0xf81f,
    0xf81f, 0x2bd7, 0xfdcd, 0x2bd7, 0xfdcd, 0xf81f,
    0xf81f, 0xfdcd, 0xfdcd, 0xfdcd, 0xfdcd, 0xf81f,
    0xf81f, 0xa324, 0xa324, 0xb841, 0xb841, 0xb841,
    0xf81f, 0xa324, 0xa324, 0xa324, 0xfdcd, 0xb841,
    0xf81f, 0xf81f, 0xc300, 0xc300, 0xb841, 0xb841,

    // frame 3/6
    0xf81f, 0xf6e5, 0xf6e5, 0xf6e5, 0xf6e5, 0xf81f,
    0xf81f, 0x2bd7, 0xfdcd, 0x2bd7, 0xfdcd, 0xf81f,
    0xf81f, 0xfdcd, 0xfdcd, 0xfdcd, 0xfdcd, 0xf81f,
    0xf81f, 0xa324, 0xa324, 0xb841, 0xb841, 0xb841,
    0xf81f, 0xa324, 0xfdcd, 0xa324, 0xa324, 0xb841,
    0xf81f, 0xc300, 0xf81f, 0xb841, 0xc300, 0xb841,

    // frame 4/6
    0xf81f, 0xf6e5, 0xf6e5, 0xf6e5, 0xf6e5, 0xf81f,
    0xf81f, 0x2bd7, 0xfdcd, 0x2bd7, 0xfdcd, 0xf81f,
    0xf81f, 0xfdcd, 0xfdcd, 0xfdcd, 0xfdcd, 0xf81f,
    0xf81f, 0xa324, 0xa324, 0xb841, 0xb841, 0xb841,
    0xfdcd, 0xa324, 0xa324, 0xa324, 0xa324, 0xb841,
    0xc300, 0xf81f, 0xf81f, 0xb841, 0xb841, 0xc300,

    // frame 5/6
    0xf81f, 0xf6e5, 0xf6e5, 0xf6e5, 0xf6e5, 0xf81f,
    0xf81f, 0x2bd7, 0xfdcd, 0x2bd7, 0xfdcd, 0xf81f,
    0xf81f, 0xfdcd, 0xfdcd, 0xfdcd, 0xfdcd, 0xf81f,
    0xf81f, 0xa324, 0xa324, 0xb841, 0xb841, 0xb841,
    0xf81f, 0xa324, 0xfdcd, 0xa324, 0xa324, 0xb841,
    0xf81f, 0xc300, 0xf81f, 0xb841, 0xc300, 0xb841,

    // frame 6/6
    0xf81f, 0xf6e5, 0xf6e5, 0xf6e5, 0xf6e5, 0xf81f,
    0xf81f, 0x2bd7, 0xfdcd, 0x2bd7, 0xfdcd, 0xf81f,
    0xf81f, 0xfdcd, 0xfdcd, 0xfdcd, 0xfdcd, 0xf81f,
    0xf81f, 0xa324, 0xa324, 0xb841, 0xb841, 0xb841,
    0xf81f, 0xa324, 0xa324, 0xa324, 0xfdcd, 0xb841,
    0xf81f, 0xf81f, 0xc300, 0xc300, 0xb841, 0xb841
};

const uint16_t ROCK_DATA[] = {

    // metadata

    8,      // frame width
    8,      // frame height
    1,      // frames
    0,      // frame loop
    0xf81f, // transparent color
    0,      // 16-bits color mode

    // colormap

    0x628a, 0x838e, 0x838e, 0x838e, 0x838e, 0x838e, 0x8bcf, 0x628a,
    0x628a, 0x8bcf, 0x8bcf, 0x8bcf, 0x8bcf, 0x838e, 0x838e, 0x838e,
    0x838e, 0x8bcf, 0x8bcf, 0x628a, 0x628a, 0x838e, 0x838e, 0x838e,
    0x838e, 0x838e, 0x838e, 0x628a, 0x838e, 0x838e, 0x838e, 0x838e,
    0x628a, 0x628a, 0x628a, 0x628a, 0x628a, 0x628a, 0x628a, 0x628a,
    0x628a, 0x628a, 0x2146, 0x628a, 0x628a, 0x628a, 0x628a, 0x2146,
    0x628a, 0x2146, 0x2146, 0x2146, 0x2146, 0x628a, 0x2146, 0x2146,
    0x2146, 0x2146, 0x2146, 0x2146, 0x2146, 0x2146, 0x2146, 0x2146

};

const uint16_t WALL_DATA[] = {

    // metadata

    8,      // frame width
    8,      // frame height
    1,      // frames
    0,      // frame loop
    0xf81f, // transparent color
    0,      // 16-bits color mode

    // colormap

    0x31a6, 0x4228, 0x4228, 0x4228, 0x31a6, 0x73ae, 0x528a, 0x73ae,
    0x4228, 0x73ae, 0x73ae, 0x528a, 0x4228, 0x73ae, 0x73ae, 0x528a,
    0x4228, 0x73ae, 0x528a, 0x528a, 0x4228, 0x528a, 0x528a, 0x73ae,
    0x4228, 0x528a, 0x73ae, 0x73ae, 0x4228, 0x4228, 0x4228, 0x31a6,
    0x31a6, 0x4228, 0x4228, 0x4228, 0x31a6, 0x528a, 0x528a, 0x4228,
    0x528a, 0x528a, 0x528a, 0x4228, 0x528a, 0x528a, 0x73ae, 0x4228,
    0x73ae, 0x73ae, 0x528a, 0x4228, 0x73ae, 0x528a, 0x528a, 0x4228,
    0x39c7, 0x73ae, 0x73ae, 0x31a6, 0x4228, 0x4228, 0x4228, 0x31a6

};

const uint16_t HOLE_DATA[] = {

    // metadata

    8,      // frame width
    8,      // frame height
    1,      // frames
    0,      // frame loop
    0xf81f, // transparent color
    0,      // 16-bits color mode

    // colormap

    0x5ad1, 0x5ad1, 0x2124, 0x2124, 0x2124, 0x2124, 0x5ad1, 0x5ad1,
    0x5ad1, 0x2124, 0x10a2, 0x0861, 0x0861, 0x10a2, 0x10a2, 0x5ad1,
    0x2124, 0x2124, 0x0861, 0x0861, 0x0861, 0x0861, 0x10a2, 0x5ad1,
    0x2124, 0x10a2, 0x0861, 0x0000, 0x0000, 0x0861, 0x10a2, 0x2124,
    0x2124, 0x10a2, 0x0861, 0x0000, 0x0000, 0x0861, 0x10a2, 0x2124,
    0x2124, 0x10a2, 0x0861, 0x0861, 0x0861, 0x0861, 0x10a2, 0x5ad1,
    0x5ad1, 0x2124, 0x10a2, 0x10a2, 0x10a2, 0x10a2, 0x10a2, 0x5ad1,
    0x5ad1, 0x5ad1, 0x2124, 0x10a2, 0x2124, 0x2124, 0x5ad1, 0x5ad1
};

const uint16_t FLOOR_DATA[] = {

    // metadata

    8,      // frame width
    8,      // frame height
    1,      // frames
    0,      // frame loop
    0xf81f, // transparent color
    0,      // 16-bits color mode

    // colormap

    0x5ad1, 0x5ad1, 0x5ad1, 0x5ad1, 0x5ad1, 0x5ad1, 0x5ad1, 0x5ad1,
    0x5ad1, 0x6b72, 0x6b72, 0x6b72, 0x6b72, 0x6b72, 0x6b72, 0x5ad1,
    0x5ad1, 0x6b72, 0x6b72, 0x6b72, 0x6b72, 0x6b72, 0x6b72, 0x5ad1,
    0x5ad1, 0x6b72, 0x6b72, 0x6b72, 0x6b72, 0x6b72, 0x6b72, 0x5ad1,
    0x5ad1, 0x6b72, 0x6b72, 0x6b72, 0x6b72, 0x6b72, 0x6b72, 0x5ad1,
    0x5ad1, 0x6b72, 0x6b72, 0x6b72, 0x6b72, 0x6b72, 0x6b72, 0x5ad1,
    0x5ad1, 0x6b72, 0x6b72, 0x6b72, 0x6b72, 0x6b72, 0x6b72, 0x5ad1,
    0x5ad1, 0x5ad1, 0x5ad1, 0x5ad1, 0x5ad1, 0x5ad1, 0x5ad1, 0x5ad1

};

const uint16_t END_DATA[] = {

    // metadata

    8,      // frame width
    8,      // frame height
    1,      // frames
    0,      // frame loop
    0xf81f, // transparent color
    0,      // 16-bits color mode

    // colormap

    0x5ad1, 0x5ad1, 0x5ad1, 0x5ad1, 0x5ad1, 0x5ad1, 0x5ad1, 0x5ad1,
    0x5ad1, 0xf7e9, 0xf7e9, 0xf7e9, 0xf7e9, 0xf7e9, 0xf7e9, 0x5ad1,
    0x5ad1, 0xf7e9, 0xf7e9, 0xf7e9, 0xf7e9, 0xf7e9, 0xf7e9, 0x5ad1,
    0x5ad1, 0xf7e9, 0xf7e9, 0xf7e9, 0xf7e9, 0xf7e9, 0xf7e9, 0x5ad1,
    0x5ad1, 0xf7e9, 0xf7e9, 0xf7e9, 0xf7e9, 0xf7e9, 0xf7e9, 0x5ad1,
    0x5ad1, 0xf7e9, 0xf7e9, 0xf7e9, 0xf7e9, 0xf7e9, 0xf7e9, 0x5ad1,
    0x5ad1, 0xf7e9, 0xf7e9, 0xf7e9, 0xf7e9, 0xf7e9, 0xf7e9, 0x5ad1,
    0x5ad1, 0x5ad1, 0x5ad1, 0x5ad1, 0x5ad1, 0x5ad1, 0x5ad1, 0x5ad1

};

const uint16_t FILLED_DATA[] = {

    // metadata

    8,      // frame width
    8,      // frame height
    1,      // frames
    0,      // frame loop
    0xf81f, // transparent color
    0,      // 16-bits color mode

    // colormap

    0x52cf, 0x52cf, 0x52cf, 0x52cf, 0x52cf, 0x52cf, 0x52cf, 0x52cf,
    0x52cf, 0x6b72, 0x6b72, 0x6b72, 0x6b72, 0x0000, 0x6b72, 0x52cf,
    0x52cf, 0x628a, 0x838e, 0x838e, 0x838e, 0x838e, 0x628a, 0x52cf,
    0x52cf, 0x628a, 0x8bcf, 0x8bcf, 0x838e, 0x838e, 0x628a, 0x52cf,
    0x52cf, 0x838e, 0x8bcf, 0x628a, 0x628a, 0x8bcf, 0x838e, 0x52cf,
    0x52cf, 0x838e, 0x838e, 0x628a, 0x838e, 0x838e, 0x8bcf, 0x52cf,
    0x52cf, 0x838e, 0x838e, 0x0000, 0x838e, 0x838e, 0x838e, 0x52cf,
    0x52cf, 0x52cf, 0x52cf, 0x52cf, 0x52cf, 0x52cf, 0x52cf, 0x52cf

};