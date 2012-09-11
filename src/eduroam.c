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
#include "authif.h"
#include "lmcons.h"
#include "ntsecapi.h"
#include "eduroam.h"

DWORD WINAPI RadiusExtensionProcess2(PRADIUS_EXTENSION_CONTROL_BLOCK pECB)
{
   PRADIUS_ATTRIBUTE_ARRAY pInAttrs, pResponseAttrs;
   const RADIUS_ATTRIBUTE* pAttr;
   int nChar;
   WCHAR wszUserName[UNLEN];
   CHAR szUserName[UNLEN];
   LSA_UNICODE_STRING lusName;
   NTSTATUS status;
   PLSA_REFERENCED_DOMAIN_LIST pReferencedDomains;
   PLSA_TRANSLATED_SID pSids;
   DWORD cbDataLength, dwResult;
   RADIUS_ATTRIBUTE raNewName;

   /* We only process authorization. */
   if (pECB->repPoint != repAuthorization)
   {
	  return NO_ERROR;
   }

   /* We only process Access-Requests followed by Access-Accept. */
   if (pECB->rcRequestType != rcAccessRequest || pECB->rcResponseType != rcAccessAccept)
   {
	  return NO_ERROR;
   }

   /* Don't process if it's already been rejected. */
   if (pECB->rcResponseType == rcAccessReject)
   {
	  return NO_ERROR;
   }

   /* Get the attributes from the Access-Request. */
   pInAttrs = pECB->GetRequest(pECB);

   /* Retrieve the username. */
   pAttr = RadiusFindFirstAttribute(pInAttrs, ratUserName);
   if (pAttr == NULL)
   {
	  return NO_ERROR;
   }

   /* Add "User-Name" attribute to Access-Accept. */  
   pResponseAttrs = pECB->GetResponse(pECB, rcAccessAccept);
   if(pResponseAttrs != NULL)
   {
	   pResponseAttrs->Add(pResponseAttrs, pAttr);
   }

   return NO_ERROR;
}
