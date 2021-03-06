/* $Id:$ */
/**
 * @file   TCatPadManager.h
 * @date   Created : Feb 06, 2012 18:06:59 JST
 *   Last Modified : Feb 24, 2014 17:27:31 JST
 * @author Shinsuke OTA <ota@cns.s.u-tokyo.ac.jp>
 *  
 *  
 *    Copyright (C)2012
 */
#ifndef TCATPADMANAGER_H
#define TCATPADMANAGER_H

#include <TCanvas.h>

class TCatPadManager  {
protected:
   TCatPadManager();
public:
   ~TCatPadManager();
   static TCatPadManager *Instance();
   TVirtualPad *Next();
   TVirtualPad *Current();
   TVirtualPad *Get(Int_t idx);
   TCanvas *GetCanvas();
   void Closed();
   Bool_t HasChild();
   Int_t GetNumChild();
   void CreateCanvas();
   void Divide(Int_t nx, Int_t ny, 
                 Float_t xmargin = 0.01, Float_t ymargin = 0.01);

   TCanvas *fCurrent;
   Int_t    fCurrentPadId;
   Int_t    fNumSubPads;

   ClassDef(TCatPadManager,0); // pad manager
};
#endif // end of #ifdef TCATPADMANAGER_H
