/*
 * Proland: a procedural landscape rendering library.
 * Copyright (c) 2008-2011 INRIA
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Proland is distributed under a dual-license scheme.
 * You can obtain a specific license from Inria: proland-licensing@inria.fr.
 */

/*
 * Authors: Eric Bruneton, Antoine Begault, Guillaume Piolat.
 */

uniform sampler2DArray elevationSampler;
uniform vec4 elevationOSL;

#ifdef _VERTEX_

layout(location = 0) in vec4 vertex;
out vec2 uv;

void main() {
    gl_Position = vertex;
    uv = (vertex.xy * 0.5 + 0.5) * elevationOSL.z + elevationOSL.xy;
}

#endif

#ifdef _FRAGMENT_

in vec2 uv;
layout(location = 0) out vec4 data;

void main() {
    vec4 zfc = textureLod(elevationSampler, vec3(uv, elevationOSL.w), 0.0);
    data = mod(zfc.z, 10.0) < 1.0 ? vec4(1.0, 0.0, 0.0, 1.0) : vec4(0.0, 1.0, 0.0, 1.0);
}

#endif
