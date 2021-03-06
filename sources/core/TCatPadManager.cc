/* $Id:$ */
/**
 * @file   TCatPadManager.cc
 * @date   Created : Feb 06, 2012 19:06:29 JST
 *   Last Modified : Mar 03, 2014 14:09:38 JST
 * @author Shinsuke OTA <ota@cns.s.u-tokyo.ac.jp>
 *  
 *  
 *    Copyright (C)2012
 */
#include "TCatPadManager.h"

#include <TList.h>

TCatPadManager::TCatPadManager()
{
   CreateCanvas();
}
TCatPadManager::~TCatPadManager()
{
}

TCatPadManager* TCatPadManager::Instance()
{
   static TCatPadManager instance;
   return &instance;
}

void TCatPadManager::CreateCanvas()
{
   fCurrent = new TCanvas("artcanvas","canvas",800,800);
   fCurrent->Connect("Closed()","TCatPadManager",this,"Closed()");
   fCurrentPadId = 0;
   fNumSubPads = 0;
}

Int_t TCatPadManager::GetNumChild()
{
   return fNumSubPads;
}

Bool_t TCatPadManager::HasChild()
{
   return GetNumChild() ? kTRUE : kFALSE;
}

TVirtualPad *TCatPadManager::Next()
{
   GetCanvas();
   if (!HasChild()) {
      fCurrentPadId = 0;
      return fCurrent->cd(0);
   } else if (fCurrentPadId + 1 <= GetNumChild()) {
      fCurrentPadId++;
      return fCurrent->cd(fCurrentPadId);
   } else {
      return fCurrent->cd((fCurrentPadId=1));
   }
}

TVirtualPad *TCatPadManager::Current()
{
   return fCurrent->GetPad(fCurrentPadId);
}

TVirtualPad* TCatPadManager::Get(Int_t idx)
{
   return fCurrent->GetPad(idx);
}

TCanvas *TCatPadManager::GetCanvas() 
{
   if (!fCurrent) CreateCanvas();
   return fCurrent;
}


void TCatPadManager::Closed()
{
   fCurrent = 0;
   fCurrentPadId = 0;
   fNumSubPads = 0;
}
void TCatPadManager::Divide(Int_t nx, Int_t ny, 
                            Float_t xmargin, Float_t ymargin)
{
   GetCanvas()->Clear();
   fCurrent->Divide(nx,ny,xmargin,ymargin);
   fCurrentPadId = 0;
   fNumSubPads = nx * ny;
}
