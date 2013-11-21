/* $Id:$ */
/**
 * @file   TSegmentedData.h
 * @date   Created : Jul 16, 2013 22:16:53 JST
 *   Last Modified : Nov 21, 2013 11:38:54 JST
 * @author Shinsuke OTA <ota@cns.s.u-tokyo.ac.jp>
 *  
 *  
 *    Copyright (C)2013
 */
#ifndef TSEGMENTEDDATA_H
#define TSEGMENTEDDATA_H

#include <TClonesArray.h>
namespace art {
   class TSegmentedData;
}

class art::TSegmentedData  : public TObjArray {

public:
   TSegmentedData();
   virtual ~TSegmentedData();

   
   virtual TObjArray *NewSegment(Int_t id) {
      TObject *obj = fgArray->ConstructedAt(fgArray->GetEntriesFast());
      obj->SetUniqueID(id);
      Add(obj);
      return (TObjArray*) obj;
   }
   virtual TObjArray* FindSegmentByID(Int_t id) {
      const Int_t &n = GetEntriesFast();
      for (Int_t i=0; i!=n; i++) {
         if (At(i)->GetUniqueID() == id) return (TObjArray*)At(i);
      }
      return NULL;
   }

   virtual TObjArray* FindSegment(const Int_t dev, const Int_t fp, const Int_t det) {
      Int_t id;
      id = (dev << 20) + (fp << 14) + (det << 8);
      return FindSegmentByID(id);
   }


protected:
   static TClonesArray *fgArray; //!
   
   ClassDef(TSegmentedData,1);
};
#endif // end of #ifdef TSEGMENTEDDATA_H
