/* 
Copyright (c) Klemen Bratec, Sola prihodnosti Maribor - 2012

This file is part of "eduroam-ms".

"eduroam-ms" is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

"eduroam-ms" is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with "eduroam-ms".  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef RADUTIL_H
#define RADUTIL_H
#pragma once

#include "authif.h"

#ifdef __cplusplus
extern "C" {
#endif

#define RADIUS_ATTR_NOT_FOUND ((DWORD)-1)

/* NPS extension entry point */
__declspec(dllexport) DWORD WINAPI RadiusExtensionProcess2(__inout  PRADIUS_EXTENSION_CONTROL_BLOCK pECB);

/* Returns the first attribute with the desired type or NULL if no such attribute exists. */
const RADIUS_ATTRIBUTE* WINAPI RadiusFindFirstAttribute(PRADIUS_ATTRIBUTE_ARRAY pAttrs, DWORD dwAttrType);

#ifdef __cplusplus
}
#endif
#endif
