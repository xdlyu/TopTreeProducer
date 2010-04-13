#ifndef TRootEvent_h
#define TRootEvent_h

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>

#include "Rtypes.h"
#include "TObject.h"
#include "TVector3.h"

using namespace std;

namespace TopTree
{
	class TRootEvent : public TObject
	{
	
	public:
	
		TRootEvent() : 
			nb_(0)
			,eventId_(-1)
			,runId_(-1)
			,lumiBlockId_(-1)
			,nTracks_(-1)
			,nHighPurityTracks_(-1)
			,passGlobalL1_(false)
			,passGlobalHLT_(false)
			,trigHLT_(0)
			,idParton1_(-1)
			,xParton1_(-1.)
			,idParton2_(-1)
			,xParton2_(-1.)
			,factorizationScale_(-1.)
			{;}

		~TRootEvent() {;}

		// Event number
		Int_t nb() const { return nb_; }
		Int_t eventId() const { return eventId_; }
		Int_t runId() const { return runId_; }
		Int_t lumiBlockId() const {return lumiBlockId_; }
		// generalTracks infos (for cleaning of the scraping events)
		Int_t nTracks() const { return nTracks_; }
		Int_t nHighPurityTracks() const { return nHighPurityTracks_; }
		// Trigger decision
		Int_t passGlobalL1() const { return passGlobalL1_; }
		Bool_t passGlobalHLT() const { return passGlobalHLT_; }
		unsigned int nHLTPaths() const { return trigHLT_.size(); }
		std::vector<Bool_t> trigHLT() const { return trigHLT_; }
		Bool_t trigHLT(unsigned int i) const
		{
			if (trigHLT_.size()>i)
			{
				return trigHLT_.at(i); 
			}
			else
			{
				cout << "HLT path " << i << " not found" << endl;
				return false;
			}
		}
		
		// PDF infos
		// flavour first incoming parton
		Int_t idParton1() const { return idParton1_; }
		// energy fraction carried by first incoming parton
		Float_t xParton1() const { return xParton1_; }
		// flavour first incoming parton
		Int_t idParton2() const { return idParton2_; }
		// energy fraction carried by first incoming parton
		Float_t xParton2() const { return xParton2_; }
		// Factorization Scale Q
		Float_t factorizationScale() const { return factorizationScale_; }


		void setNb(Int_t nb) { nb_ = nb; }
		void setEventId(Int_t eventId) { eventId_ = eventId; }
		void setRunId(Int_t runId) { runId_ = runId; }
		void setLumiBlockId(Int_t lumiBlockId) { lumiBlockId_ = lumiBlockId; }
		void setNTracks(Int_t nTracks) { nTracks_ = nTracks; }
		void setNHighPurityTracks(Int_t nHighPurityTracks) { nHighPurityTracks_ = nHighPurityTracks; }
		void setGlobalL1(Int_t passGlobalL1) { passGlobalL1_ = passGlobalL1; }
		void setGlobalHLT(Bool_t passGlobalHLT) { passGlobalHLT_ = passGlobalHLT; }
		void setTrigHLT(std::vector<Bool_t> trigHLT)
		{
			trigHLT_.resize(trigHLT.size());
			for (unsigned int i=0; i!=trigHLT.size(); ++i) trigHLT_[i]=trigHLT[i];
		}

		void setIdParton1(Int_t idParton1) { idParton1_=idParton1; }
		void setXParton1(Float_t xParton1) { xParton1_=xParton1; }
		void setIdParton2(Int_t idParton2) { idParton2_=idParton2; }
		void setXParton2(Float_t xParton2) { xParton2_=xParton2; }
		void setFactorizationScale(Float_t factorizationScale) { factorizationScale_=factorizationScale; }

		/*
		// FIXME
		friend std::ostream& operator<< (std::ostream& stream, const TRootEvent& event) {
			stream << "Event #"<< event.nb() <<"  L1="<< event.trigL1() <<"  HLT="<< event.trigHLT();
			return stream;
		};
		*/
	
	private:
	
		Int_t nb_;
		Int_t eventId_;
		Int_t runId_;
		Int_t lumiBlockId_;
		
		// generalTracks infos (for cleaning of the scraping events)
		Int_t nTracks_;
		Int_t nHighPurityTracks_;

		// Trigger Infos
		Bool_t passGlobalL1_;
		Bool_t passGlobalHLT_;
		std::vector<Bool_t> trigHLT_;

		// PDF infos
		Int_t idParton1_;
		Float_t xParton1_;
		Int_t idParton2_;
		Float_t xParton2_;
		Float_t factorizationScale_;

		ClassDef (TRootEvent,2);
	};
}

#endif
