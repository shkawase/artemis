/**
 * @file   TRawDataPair.h
 * @brief  Rawdata container with two values
 *
 * @date   Created:       2013-07-25 10:19:08
 *         Last Modified: 2013-11-20 10:01:58
 * @author KAWASE Shoichiro <kawase@cns.s.u-tokyo.ac.jp>
 *
 * @note   This class contains two Int_t values
 *         You can access the values via (Get|Set)(First|Second) and operator[].
 *
 *    Copyright (C) 2013 KAWASE Shoichiro All rights reserved
 */

#ifndef TRAWDATAPAIR_H
#define TRAWDATAPAIR_H

#include <TRawDataObject.h>

namespace art {
   class TRawDataPair;
}

class art::TRawDataPair : public TRawDataObject {
public:
   // Default constructor
   TRawDataPair();
   virtual ~TRawDataPair();
   // Copy constructor
   TRawDataPair(const TRawDataPair& rhs);
   // Assignment operator
   TRawDataPair& operator=(const TRawDataPair& rhs);

   // offers array-like access: idx = 0 -> fFirst, 1 -> fSecond
   Int_t& operator[](Int_t idx);

   void SetFirst(Int_t first) { fFirst = first; }
   void SetSecond(Int_t second) { fSecond = second; }

   Int_t GetFirst() const { return fFirst; }
   Int_t GetSecond() const { return fSecond; }

   // swap fFirst and fSecond
   void Swap();

   virtual void Clear(Option_t *opt="") {
      TRawDataObject::Clear(opt);
      fFirst  = TRawDataObject::kInvalid;
      fSecond = TRawDataObject::kInvalid;
   }

private:
   Int_t fFirst;
   Int_t fSecond;

   ClassDef(TRawDataPair, 1);
};

#endif // TRAWDATAPAIR_H


