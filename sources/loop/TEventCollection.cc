/* $Id:$ */
/**
 * @file   TEventCollection.cc
 * @date   Created : Jul 10, 2013 17:10:20 JST
 *   Last Modified : 2014-03-04 09:14:32 (kawase)
 * @author Shinsuke OTA <ota@cns.s.u-tokyo.ac.jp>
 *  
 *  
 *    Copyright (C)2013
 */
#include "TEventCollection.h"

using art::TEventCollection;


TEventCollection::TEventCollection()
{
   fObjects = new TList;
   fUserInfo = new TList;
}
TEventCollection::~TEventCollection()
{
   delete fObjects;
   delete fUserInfo;
}


void TEventCollection::Add(const char* name, TObject* obj, Bool_t isPassive)
{
   fObjects->Add(new TEventObject(name,obj,isPassive));
}

void TEventCollection::AddInfo(const char *name, TObject *obj, Bool_t isPassive)
{
   fUserInfo->Add(new TEventObject(name,obj,isPassive));
}

art::TEventObject* TEventCollection::Get(const char* name)
{
   return (TEventObject*) fObjects->FindObject(name);
}

void** TEventCollection::GetObjectRef(const char *name) {
   TObject *obj = NULL;
   if (!(obj = fObjects->FindObject(name))) {
      printf("<art::TEventCollection::GetReference> no such object %s\n",name);
      return NULL;
   }
   return (void**)((TEventObject*)obj)->GetObjectRef();
}

TObject* TEventCollection::GetInfo(const char *name) {
   TObject *obj = NULL;
   if (!(obj = fUserInfo->FindObject(name))) {
      printf("<art::TEventCollection::GetInfo> no such info %s\n",name);
      return NULL;
   }
   return *(TObject**)((TEventObject*)obj)->GetObjectRef();
}   


void art::TEventCollection::Delete()
{
   fObjects->Delete();
   fUserInfo->Delete();
}
