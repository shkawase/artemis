/* $Id:$ */
/**
 * @file   TMappingProcessor.h
 * @date   Created : Nov 22, 2013 17:22:13 JST
 *   Last Modified : Nov 22, 2013 18:16:02 JST
 * @author Shinsuke OTA <ota@cns.s.u-tokyo.ac.jp>
 *  
 *  
 *    Copyright (C)2013
 */
#ifndef TMAPPINGPROCESSOR_H
#define TMAPPINGPROCESSOR_H

#include <TProcessor.h>

namespace art {
   class TMappingProcessor;
   class TCategorizedData;
   class TSegmentedData;
   class TMapTable;
}

class art::TMappingProcessor  : public TProcessor {

public:
   TMappingProcessor();
   ~TMappingProcessor();

   virtual void Process();

protected:
   virtual void Init(TEventCollection *col);
   
   StringVec_t fInputColName; // Name of input collections
   TString     fNameCategorized; // name of output collection
   TString     fMapConfigName; // name of mapper configuration file
   TCategorizedData  *fCategorizedData; //! pointer to categorized data
   TSegmentedData   **fSegmentedData; //! pointer to segmented data
   TMapTable         *fMapTable; //! pointer to map table

   ClassDef(TMappingProcessor,1); // mapping processor from TSegmentedData to TCategorizedData
};
#endif // end of #ifdef TMAPPINGPROCESSOR_H
