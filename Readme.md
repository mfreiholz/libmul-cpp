# Manuel's C++ Utility Library (MUL)

A C++ library... \
Easy to build, no other dependencies and everything is written as simple as possible.

## Versioning

I try to keep up a semantic versioning and also try not to break the ABI.

## Notes
The project has been structured based on this guide: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p1204r0.html

## Submodule Dependency Graph/Layers

| Core |
| Net | Unit |
| Geom |
| Geo |

## Coding Rules

**Not allowed:**
- Exceptions
- Spaces for indentation

**Musts:**
- Handle errors before return
- Use error codes or similar
- Prefer "expected" type to handle errors and return values
- Write a \*.test.cpp for each file
- Complicated implementations/calculations should always have good explanations (/docs, inline)
