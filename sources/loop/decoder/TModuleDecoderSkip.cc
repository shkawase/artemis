/**
 * @file   TModuleDecoderSkip.cc
 * @brief
 *
 * @date   Created:       2013-07-24 17:33:07
 *         Last Modified: 2013-07-24 17:41:21
 * @author KAWASE Shoichiro <kawase@cns.s.u-tokyo.ac.jp>
 *
 *    Copyright (C) 2013 KAWASE Shoichiro All rights reserved.
 */

#include "TModuleDecoderSkip.h"

#include <TObjArray.h>

using art::TModuleDecoderSkip;

// Default constructor
TModuleDecoderSkip::TModuleDecoderSkip(const Int_t id)
   : TModuleDecoder(id, NULL) {
   printf("[TModuleDecorderSkip] segID = %d will be skipped.\n",id);
}

// Default destructor
TModuleDecoderSkip::~TModuleDecoderSkip() {
}

// Copy constructor
TModuleDecoderSkip::TModuleDecoderSkip(const TModuleDecoderSkip& rhs)
   : TModuleDecoder(rhs.fID, NULL) {
}

// Assignment operator
TModuleDecoderSkip& TModuleDecoderSkip::operator=(const TModuleDecoderSkip& rhs) {
   if (this != &rhs) {
   }
   return *this;
}

