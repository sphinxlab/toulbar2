######################################
# personal properties for -D Option
######################################

set(PROBABILITY "DOUBLE_PROB")

if(LONG_PROBABILITY)
  set(PROBABILITY "LONGDOUBLE_PROB")
ENDIF(LONG_PROBABILITY)

if(QUAD_PROBABILITY)
  set(PROBABILITY "QUAD_PROB")
ENDIF(QUAD_PROBABILITY)

if(LONG_COSTS)
  SET(COST LONGLONG_COST)
ELSE(LONG_COSTS)
  set(COST INT_COST)
ENDIF(LONG_COSTS)

  IF(TOULBAR2)
    set_property(
      TARGET toulbar2
      PROPERTY COMPILE_DEFINITIONS WCSPFORMATONLY ${COST} ${XMLFLAG} ${boostflag} ${mpiflag} ${PROBABILITY})
    set_property(
      TARGET tb2-archive
      PROPERTY COMPILE_DEFINITIONS ${COST} ${XMLFLAG} ${boostflag} ${mpiflag} ${PROBABILITY})
    set_property(
      TARGET tb2-objects
      PROPERTY COMPILE_DEFINITIONS ${COST} ${XMLFLAG} ${boostflag} ${mpiflag} ${PROBABILITY})
  ENDIF(TOULBAR2)
  
  IF(MENDELSOFT)
    set_property(
      TARGET mendelsoft
      PROPERTY COMPILE_DEFINITIONS WCSPFORMATONLY ${COST} MENDELSOFT ${boostflag} ${mpiflag} ${PROBABILITY})
  ENDIF(MENDELSOFT)
  
  IF(LIBTB2)
    set_property(
      TARGET tb2-PIC-objects
      PROPERTY COMPILE_DEFINITIONS ${COST} ${XMLFLAG} ${boostflag} ${mpiflag} ${PROBABILITY})
    set_property(
      TARGET tb2
      PROPERTY COMPILE_DEFINITIONS ${COST} ${XMLFLAG} ${boostflag} ${mpiflag} ${PROBABILITY})
    IF(PYTB2)
      set_property(
	TARGET pytoulbar2
	PROPERTY COMPILE_DEFINITIONS ${COST} ${XMLFLAG} ${boostflag} ${mpiflag} ${PROBABILITY})
    ENDIF(PYTB2)
  ENDIF(LIBTB2)
  
  if(ILOG)
    set_property(
      TARGET iloglue
      PROPERTY COMPILE_DEFINITIONS WCSPFORMATONLY INT_COST ILOGLUE IL_STD ${PROBABILITY})
  ENDIF(ILOG)
