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

#include "windows.h"
#include "eduroam.h"

DWORD WINAPI RadiusFindFirstIndex(PRADIUS_ATTRIBUTE_ARRAY pAttrs, DWORD dwAttrType)
{
   DWORD dwIndex, dwSize;
   const RADIUS_ATTRIBUTE *pAttr;

   if (pAttrs == NULL)
   {
      return RADIUS_ATTR_NOT_FOUND;
   }

   dwSize = pAttrs->GetSize(pAttrs);

   for (dwIndex = 0; dwIndex < dwSize; ++dwIndex)
   {
      pAttr = pAttrs->AttributeAt(pAttrs, dwIndex);
      if (pAttr->dwAttrType == dwAttrType)
      {
         return dwIndex;
      }
   }

   return RADIUS_ATTR_NOT_FOUND;
}

const RADIUS_ATTRIBUTE* WINAPI RadiusFindFirstAttribute(PRADIUS_ATTRIBUTE_ARRAY pAttrs, DWORD dwAttrType)
{
   DWORD dwIndex;

   dwIndex = RadiusFindFirstIndex(pAttrs, dwAttrType);

   if (dwIndex != RADIUS_ATTR_NOT_FOUND)
   {
      return pAttrs->AttributeAt(pAttrs, dwIndex);
   }
   else
   {
      return NULL;
   }
}
