/* $Id:$ */
/**
 * @file   TDataObject.cc
 * @date   Created : Jan 07, 2014 10:07:26 JST
 *   Last Modified : Jan 08, 2014 14:00:17 JST
 * @author Shinsuke OTA <ota@cns.s.u-tokyo.ac.jp>
 *  
 *  
 *    Copyright (C)2014
 */
#include "TDataObject.h"
#include <TClass.h>
#include <iostream>

ClassImp(art::TDataObject);

using art::TDataObject;

TDataObject::TDataObject()
   : fID(0),fAuxID(0), fQuality(kInvalid)
{
}

TDataObject::TDataObject(const TDataObject &obj)
   : TArtemisObject(obj), fID(obj.fID), fAuxID(obj.fAuxID), fQuality(obj.fQuality)
{
}

TDataObject::~TDataObject()
{
}

void TDataObject::Clear(Option_t *option)
{
   fID = fAuxID = 0;
   fQuality = kInvalid;
   TObject::Clear(option);
}

void TDataObject::Copy(TObject &object) const
{
   TDataObject &obj = *(TDataObject*)&object;
   obj.fID = fID;
   obj.fAuxID = fAuxID;
   obj.fQuality = fQuality;
   TObject::Copy(obj);
}

void TDataObject::Print(Option_t*) const
{
   std::cout << "OBJ:" << IsA()->GetName() << "\t" << "ID = " << fID << "\t" << "AuxID = " << fAuxID << std::endl;
}

TDataObject& TDataObject::operator=(const TDataObject &rhs)
{
   if (this != &rhs) {
      const TDataObject& obj = *(TDataObject*)&rhs;
      fID = obj.fID;
      fAuxID = obj.fAuxID;
      fQuality = obj.fQuality;
   }
   return *this;
}


void TDataObject::SetQualityBit(UInt_t quality, Bool_t set)
{
   if (set) {
      SetQualityBit(quality);
   } else {
      ResetQualityBit(quality);
   }
}
