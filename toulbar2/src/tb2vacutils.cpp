/*
 * ****** Set of useful classes to enforce VAC
 */
 
#include "tb2vacutils.hpp"
#include "tb2vac.hpp"
#include "tb2clusters.hpp"



VACVariable::VACVariable (WCSP *wcsp, string n, Value iinf, Value isup) : EnumeratedVariable(wcsp, n, iinf, isup)
				,vac(wcsp->vac), myThreshold(MIN_COST, &wcsp->getStore()->storeCost) 
{
  init();
}

VACVariable::VACVariable (WCSP *wcsp, string n, Value *d, int dsize) : EnumeratedVariable(wcsp, n, d, dsize)
				,vac(wcsp->vac), myThreshold(MIN_COST, &wcsp->getStore()->storeCost) 																	   
{
  init();
}

VACVariable::~VACVariable () {
}

void VACVariable::init () {
  for (unsigned int a = 0; a < getDomainInitSize(); a++) {
  	mark.push_back(0);
  	k_timeStamp.push_back(0);
  	k.push_back(0);
  	killer.push_back(0);
  }
  linkVACQueue.content.var = this;
  linkVACQueue.content.timeStamp = -1;
  linkSeekSupport.content.var = this;
  linkSeekSupport.content.timeStamp = -1;
  linkVAC2Queue.content = this;
}

 
bool VACVariable::increaseVAC(Value newInf) {
    if (newInf > inf) {
    	if(newInf > sup) return true;
    	else {
	        newInf = domain.increase(newInf);
	        inf = newInf;
    	}
    }
   	return false;
}

bool VACVariable::decreaseVAC(Value newSup) {
    if (newSup < sup) {
    	if(newSup < inf) return true;
    	else {
	        newSup = domain.decrease(newSup);
	        sup = newSup;
    	}
   }
   return false;
}

bool VACVariable::removeVAC ( Value v )
{
    if (v == inf) return increaseVAC(v + 1);
    else if (v == sup) return decreaseVAC(v - 1);
	else if (canbe(v)) domain.erase(v);
	return false;
}

void VACVariable::decreaseCost(Value v, Cost c) {	
  assert(c > MIN_COST);
  Cost cini = getCost(v);  
  if (wcsp->getLb() + cini < wcsp->getUb()) {
    costs[toIndex(v)] -= c;
  }
}


void VACVariable::VACproject (Value v, const Cost c) {
//   Cost oldCost = getVACCost(v);
  costs[toIndex(v)] += c;
//   Cost newCost = getVACCost(v);
  
//   if ((v == maxCostValue) || (newCost > maxCost) || CUT(wcsp->getLb() + newCost,wcsp->getUb())) {
   if (CUT(wcsp->getLb() + getCost(v), wcsp->getUb())) {
     queueNC();
   }
//   if (oldCost == MIN_COST) {
//     queueNC();
//     queueDAC();
//     queueEAC1();
//   }
//   if ((isNull(oldCost)) && (!isNull(newCost))) {
//     queueVAC2();
//   }
  
//   if(v == getSupport()) { 
//     Value newSupport = getInf();
//     Cost minCost = getCost(newSupport);
//     EnumeratedVariable::iterator iter = begin();
//     for (++iter; minCost > MIN_COST && iter != end(); ++iter) {
//         Cost cost = getCost(*iter);
//         if (cost < minCost) {
//             minCost = cost;
//             newSupport = *iter;
//         }
//     }
// 	assert(canbe(newSupport));
// 	//	cout << "setsupport " << wcspIndex << " " << newSupport << endl;
// 	setSupport(newSupport);
//   } 
}

void VACVariable::VACextend (Value v, const Cost c) {
  decreaseCost(v,c);
  if (v == maxCostValue) queueNC();
  assert(canbe(getSupport()));
//   if(cannotbe(getSupport()) || getCost(getSupport())>MIN_COST) { // TO BE REMOVED ???
//     Value newSupport = getInf();
//     Cost minCost = getCost(newSupport);
//     EnumeratedVariable::iterator iter = begin();
//     for (++iter; minCost > MIN_COST && iter != end(); ++iter) {
//         Cost cost = getCost(*iter);
//         if (cost < minCost) {
//             minCost = cost;
//             newSupport = *iter;
//         }
//     }
// 	assert(canbe(newSupport));
// 	//	cout << "setsupport " << wcspIndex << " " << newSupport << endl;
// 	setSupport(newSupport);
//   } 
}

bool VACVariable::isNull (Cost c) 
{
	if(myThreshold != MIN_COST) {
		if(myThreshold > vac->getThreshold()) return c < myThreshold;
		else return c < vac->getThreshold();
	}
	else return vac->isNull(c);
}


void VACVariable::queueVAC() {
  wcsp->vac->queueVAC(&linkVACQueue);
}

void VACVariable::queueSeekSupport() {
  wcsp->vac->queueSeekSupport(&linkSeekSupport);
}

void VACVariable::queueVAC2() {
  wcsp->vac->queueVAC2(&linkVAC2Queue);
}

void VACVariable::dequeueVAC2() {
  wcsp->vac->dequeueVAC2(&linkVAC2Queue);
}

// void VACVariable::extendAll(Cost cost) {
//   VACVariable *xj;
//   if (ToulBar2::vac) {
//     for (ConstraintList::iterator iter = getConstrs()->begin(); iter != getConstrs()->end(); ++iter) {
// 	   Constraint *c = (*iter).constr;
//        if(c->arity() == 2 && !c->isSep()) {
// 		   xj = (VACVariable *) c->getVar(1 - (*iter).scopeIndex);
// 	       xj->queueVAC2();
//        }
//     }
//   }
//   EnumeratedVariable::extendAll(cost);
// }

// void VACVariable::assign(Value newValue) {
//   vac->assign(wcspIndex, newValue);
 
//   if (ToulBar2::vac) {
//     for (ConstraintList::iterator iter = getConstrs()->begin(); iter != getConstrs()->end(); ++iter) {
// 	   Constraint *c = (*iter).constr;
//        if(c->arity() == 2 && !c->isSep()) {
// 	       VACVariable *xj = (VACVariable *) c->getVar(1 - (*iter).scopeIndex);
// 	       xj->queueVAC2();
//        }
//     }
//   }
//   EnumeratedVariable::assign(newValue);
// }


void VACVariable::remove (Value value) {
  // if (canbe(value)) {
  //   queueVAC2();
  // }
  if (ToulBar2::singletonConsistency) vac->singleton.insert(100*wcspIndex + value);
  EnumeratedVariable::remove(value);
}


void VACVariable::removeFast (Value value) {
  if (ToulBar2::singletonConsistency) vac->singleton.insert(100*wcspIndex + value);
  EnumeratedVariable::removeFast(value);
}

 
// void VACVariable::project (Value value, Cost cost) {
//   assert(cost >= MIN_COST);
//   Cost oldcost = getCost(value);
//   Cost newcost = oldcost + cost;
//   if ((isNull(oldcost)) && (!isNull(newcost))) {
//     queueVAC2();
//   }
//   EnumeratedVariable::project(value, cost);
// }

// void VACVariable::extend (Value value, Cost cost) {
//   VACVariable *xj;
//   queueVAC2();
//   for (ConstraintList::iterator iter = getConstrs()->begin(); iter != getConstrs()->end(); ++iter) {
// 	Constraint *c = (*iter).constr;
// 	if(c->arity() == 2 && !c->isSep()) {
// 	  xj = (VACVariable *) c->getVar(1 - (*iter).scopeIndex);
// 	  xj->queueVAC2();
// 	}
//   }
//   EnumeratedVariable::extend(value, cost);
// }

void VACVariable::increase(Value newInf) {
  // if ((newInf > inf) && (newInf < sup)) {
  //   queueVAC2();
  // }
  if (ToulBar2::singletonConsistency) for(int i=inf;i<=newInf;i++) vac->singleton.insert(100*wcspIndex + i);
  EnumeratedVariable::increase(newInf);
}

void VACVariable::decrease(Value newSup) {
  // if ((newSup < sup) && (newSup > inf)) {
  //   queueVAC2();
  // }
  if (ToulBar2::singletonConsistency) for(int i=sup;i>=newSup;i--) vac->singleton.insert(100*wcspIndex + i);
  EnumeratedVariable::decrease(newSup);
}


/******************************
 * min-sum diffusion algorithm
 */

bool VACVariable::averaging()
{
	Cost Top = wcsp->getUb();
	bool change = false;
	EnumeratedVariable* x;
	//EnumeratedVariable* y;
	Constraint* ctr = NULL;
	ConstraintList::iterator itc = getConstrs()->begin();
	if(itc != getConstrs()->end())	ctr = (*itc).constr;
	while(ctr) {
		if(ctr->arity() == 2 && !ctr->isSep()) {
			BinaryConstraint* bctr = (BinaryConstraint*) ctr;
			x = (EnumeratedVariable*) bctr->getVarDiffFrom( (Variable*) this );
			for (iterator it = begin(); it != end(); ++it) {
				Cost cu = getCost(*it);
				Cost cmin = Top;
				for (iterator itx = x->begin(); itx != x->end(); ++itx) {
					Cost cbin = bctr->getCost(this,x,*it,*itx);
					if(cmin > cbin) cmin = cbin;
				}
				long double mean = to_double(cmin + cu) / 2.;	
				long double extc = to_double(cu) - mean;					 
				if(abs(extc) >= 1) {
				  Cost costi = (Long) extc;
					for (iterator itx = x->begin(); itx != x->end(); ++itx) {
						bctr->addcost(this,x,*it,*itx,costi);				
					}
					if(mean > to_double(cu)) project(*it, -costi); 
					else          extend(*it,   costi);
					change = true;
				}
			}
		} /*else if(ctr->arity() == 3 && !ctr->isSep()) {
			TernaryConstraint* tctr = (TernaryConstraint*) ctr;
			x = (EnumeratedVariable*) tctr->getVar( 0 );
			if(x == this) x = (EnumeratedVariable*) tctr->getVar( 1 );
		    y = (EnumeratedVariable*) tctr->getVarDiffFrom((Variable*) this, (Variable*)x);

			for (iterator it = begin(); it != end(); ++it) {
				Cost cu = getCost(*it);
				Cost cmin = Top;
				for (iterator itx = x->begin(); itx != x->end(); ++itx) {
				for (iterator ity = y->begin(); ity != y->end(); ++ity) {
					Cost ctern = tctr->getCost(this,x,y,*it,*itx,*ity);
					if(cmin > ctern) cmin = ctern;
				}}
				float mean = (float)(cmin + cu) / 2.;	
				float extc = (float)cu - mean;					 
				if(abs(extc) >= 1) {
					int costi =  (int) extc;
					for (iterator itx = x->begin(); itx != x->end(); ++itx) {
					for (iterator ity = y->begin(); ity != y->end(); ++ity) {
						tctr->addcost(this,x,y,*it,*itx,*ity,costi);				
					}}
					if(mean > cu) project(*it, -costi); 
					else          extend(*it,   costi);
					change = true;
				}
			}
		}*/
		++itc;
		if(itc != getConstrs()->end()) ctr = (*itc).constr;
		else ctr = NULL;
	}
	return change;
}


/************************************************************
 * VACConstraint:
 *   A class that stores information about a binary constraint
 */

VACConstraint::VACConstraint (WCSP *wcsp, EnumeratedVariable *xx, EnumeratedVariable *yy, vector<Cost> &tab, StoreStack<Cost, Cost> *storeCost) : BinaryConstraint(wcsp, xx, yy, tab, storeCost) 
{
   for (unsigned int a = 0; a < xx->getDomainInitSize(); a++) {
	   	kX.push_back(0);
	   	kX_timeStamp.push_back(0);
   }
   for (unsigned int b = 0; b < yy->getDomainInitSize(); b++) {
	   	kY.push_back(0);
	   	kY_timeStamp.push_back(0);
   }
}

VACConstraint::VACConstraint (WCSP *wcsp, StoreStack<Cost, Cost> *storeCost) : BinaryConstraint(wcsp, storeCost) 
{
   for (int a = 0; a < wcsp->maxdomainsize; a++) {
	   	kX.push_back(0);
	   	kX_timeStamp.push_back(0);
   }
   for (int b = 0; b < wcsp->maxdomainsize; b++) {
	   	kY.push_back(0);
	   	kY_timeStamp.push_back(0);
   }
}

VACConstraint::~VACConstraint () 
{
}

void VACConstraint::VACproject (VACVariable* x, Value v, Cost c) {
  assert(ToulBar2::verbose < 4 || ((cout << "project(C" << getVar(0)->getName() << "," << getVar(1)->getName() << ", (" << x->getName() << "," << v << "), " << c << ")" << endl), true));
    
  TreeDecomposition* td = wcsp->getTreeDec();
  if(td) td->addDelta(cluster,x,v,c);

  int index = x->toIndex(v);
  // TO BE REPLACED BY A LOOP ON THE DOMAIN IN ORDER TO AVOID SUBSTRACTING TOP???
  if(!getIndex(x)) deltaCostsX[index] += c; 
  else			   deltaCostsY[index] += c; 
  x->VACproject(v, c);
}

void VACConstraint::VACextend(VACVariable* x, Value v, Cost c) {
  assert(ToulBar2::verbose < 4 || ((cout << "extend(C" << getVar(0)->getName() << "," << getVar(1)->getName() << ", (" << x->getName() << "," << v << "), " << c << ")" << endl), true));

  TreeDecomposition* td = wcsp->getTreeDec();
  if(td) td->addDelta(cluster,x,v,-c);

  int index = x->toIndex(v);
  // TO BE REPLACED BY A LOOP ON THE DOMAIN IN ORDER TO AVOID SUBSTRACTING TOP???
  if(!getIndex(x)) deltaCostsX[index] -= c;
  else		       deltaCostsY[index] -= c;
  x->VACextend(v, c);
}

int VACConstraint::getK (VACVariable* var, Value v, long timeStamp) {
  if(var == (VACVariable*) getVar(0)) {
  	if(kX_timeStamp[var->toIndex(v)] < timeStamp) return 0;
  	else return kX[var->toIndex(v)];
  }  else  {
  	if(kY_timeStamp[var->toIndex(v)] < timeStamp) return 0;
  	else return kY[var->toIndex(v)];
  }
}

void VACConstraint::setK (VACVariable* var, Value v, int c, long timeStamp) {
  if(var == getVar(0)) {
  	kX[var->toIndex(v)] = c;
  	kX_timeStamp[var->toIndex(v)] = timeStamp;
  } else {
    kY[var->toIndex(v)] = c;
   	kY_timeStamp[var->toIndex(v)] = timeStamp; 					   
  }		
}

bool VACConstraint::revise (VACVariable* var, Value v) {
  bool wipeout = false;
  VACVariable* xi = (VACVariable*) getVar(0);
  VACVariable* xj = (VACVariable*) getVar(1);
  Value sup = getSupport(var,v);
  Value minsup = sup;
  if(var != xi) {  xi = (VACVariable*)getVar(1); xj = (VACVariable*)getVar(0); }	
  Cost cost, minCost = wcsp->getUb();

  if(xj->canbe(sup)) {	
	  if(xj->getVACCost(sup) != MIN_COST) { wipeout = xj->removeVAC(sup);  }
	  else {
		  if (getVACCost(xi,xj,v,sup) == MIN_COST) {
		    return false;
		  }
	  }
  }
   
  for (EnumeratedVariable::iterator it = xj->lower_bound(sup); it != xj->end(); ++it) {
	  Value w = *it;	
	  if(xj->getVACCost(w) != MIN_COST) { wipeout = xj->removeVAC(w); xj->queueVAC(); }
	  else {
	      cost = getVACCost(xi,xj,v, w);
	      if (cost == MIN_COST) {		
	      	setSupport(xi,v,w);
	        return false;
	      } else if (cost < minCost) {
	      	  minCost = cost;
	          minsup = w;
	      }
	  }
  }
  for (EnumeratedVariable::iterator it = xj->begin(); it != xj->lower_bound(sup); ++it) {
	  Value w = *it;	
	  if(xj->getVACCost(w) != MIN_COST) { wipeout = xj->removeVAC(w); xj->queueVAC(); }
	  else {
	      cost = getVACCost(xi,xj,v, w);
	      if (cost == MIN_COST) {		
	      	setSupport(xi,v,w);
	        return false;
	      } else if (cost < minCost) {
	      	  minCost = cost;
	          minsup = w;
	      }
	  }
  }
  
  setSupport(xi,v,minsup);
  return true;
}