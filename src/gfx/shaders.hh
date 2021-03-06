#pragma once

#include "../utils.hh"

namespace shaders {

static const char *simple_vert = _glsl(
  attribute vec2 vertex_pos;
  uniform mat4 mvp;
  void main() {
    gl_Position = mvp * vec4(vertex_pos, 0.0, 1.0);
  }
);

static const char *simple_frag = _glsl(
  void main() {
    gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
  }
);

static const char *colored_mesh_vert = _glsl(
  attribute vec2 vertex_pos;
  attribute vec3 vertex_color;
  varying vec3 vertex_color_f;
  uniform mat4 mvp;
  void main() {
    gl_Position = mvp * vec4(vertex_pos, 0.0, 1.0);
    vertex_color_f = vertex_color;
  }
);

static const char *colored_mesh_frag = _glsl(
  varying vec3 vertex_color_f;
  void main() {
    gl_FragColor = vec4(vertex_color_f, 1.0);
  }
);

static const char *black_frag = _glsl(
  void main() {
    gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);
  }
);

static const char *unif_colored_mesh_frag = _glsl(
  uniform vec3 vertex_color_unif;
  void main() {
    gl_FragColor = vec4(vertex_color_unif, 1.0);
  }
);

};

