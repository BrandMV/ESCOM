#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Ejem1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Ejem1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
<<<<<<< HEAD
SOURCEFILES_QUOTED_IF_SPACED=retardos.s PRINCIPALINT2.c interrupciones.s LCDg.s
=======
<<<<<<< HEAD
SOURCEFILES_QUOTED_IF_SPACED=retardos.s LCD.s PRINCIPALLCD.c PRINCIPALINT.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/retardos.o ${OBJECTDIR}/LCD.o ${OBJECTDIR}/PRINCIPALLCD.o ${OBJECTDIR}/PRINCIPALINT.o
POSSIBLE_DEPFILES=${OBJECTDIR}/retardos.o.d ${OBJECTDIR}/LCD.o.d ${OBJECTDIR}/PRINCIPALLCD.o.d ${OBJECTDIR}/PRINCIPALINT.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/retardos.o ${OBJECTDIR}/LCD.o ${OBJECTDIR}/PRINCIPALLCD.o ${OBJECTDIR}/PRINCIPALINT.o

# Source Files
SOURCEFILES=retardos.s LCD.s PRINCIPALLCD.c PRINCIPALINT.c
=======
SOURCEFILES_QUOTED_IF_SPACED=retardos.s PRINCIPALINT2.c LCD.s PRINCIPALLCD.c
>>>>>>> 3464e05ed4a742d17ca633fde70ffba96f77afc5

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/retardos.o ${OBJECTDIR}/PRINCIPALINT2.o ${OBJECTDIR}/interrupciones.o ${OBJECTDIR}/LCDg.o
POSSIBLE_DEPFILES=${OBJECTDIR}/retardos.o.d ${OBJECTDIR}/PRINCIPALINT2.o.d ${OBJECTDIR}/interrupciones.o.d ${OBJECTDIR}/LCDg.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/retardos.o ${OBJECTDIR}/PRINCIPALINT2.o ${OBJECTDIR}/interrupciones.o ${OBJECTDIR}/LCDg.o

# Source Files
<<<<<<< HEAD
SOURCEFILES=retardos.s PRINCIPALINT2.c interrupciones.s LCDg.s
=======
SOURCEFILES=retardos.s PRINCIPALINT2.c LCD.s PRINCIPALLCD.c
>>>>>>> da6c3107aaa705a678b9e6a09de47f9ced63c23a
>>>>>>> 3464e05ed4a742d17ca633fde70ffba96f77afc5



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Ejem1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=30F3013
MP_LINKER_FILE_OPTION=,--script="p30F3013.gld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
<<<<<<< HEAD
${OBJECTDIR}/PRINCIPALLCD.o: PRINCIPALLCD.c  .generated_files/flags/default/5580118ff4ca767879bce595d5eb2142bd9dba7c .generated_files/flags/default/33ed45b91679709b1183172806be222f11ad8a4f
=======
${OBJECTDIR}/PRINCIPALINT2.o: PRINCIPALINT2.c  .generated_files/flags/default/9bad3ed04d4da3c7682d06a10f4bc9a1c1c1a191 .generated_files/flags/default/fd67b544a79261c2fe49714d5749bb13d89b49dc
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PRINCIPALINT2.o.d 
	@${RM} ${OBJECTDIR}/PRINCIPALINT2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PRINCIPALINT2.c  -o ${OBJECTDIR}/PRINCIPALINT2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PRINCIPALINT2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
<<<<<<< HEAD
=======
${OBJECTDIR}/PRINCIPALLCD.o: PRINCIPALLCD.c  .generated_files/flags/default/d26217aefd4d80c64c66ebdf2962cdff62bd3abf .generated_files/flags/default/fd67b544a79261c2fe49714d5749bb13d89b49dc
>>>>>>> da6c3107aaa705a678b9e6a09de47f9ced63c23a
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PRINCIPALLCD.o.d 
	@${RM} ${OBJECTDIR}/PRINCIPALLCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PRINCIPALLCD.c  -o ${OBJECTDIR}/PRINCIPALLCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PRINCIPALLCD.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
<<<<<<< HEAD
${OBJECTDIR}/PRINCIPALINT.o: PRINCIPALINT.c  .generated_files/flags/default/e651474a08b757ee4418aee9cee1d2ffffc57fc0 .generated_files/flags/default/33ed45b91679709b1183172806be222f11ad8a4f
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PRINCIPALINT.o.d 
	@${RM} ${OBJECTDIR}/PRINCIPALINT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PRINCIPALINT.c  -o ${OBJECTDIR}/PRINCIPALINT.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PRINCIPALINT.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
=======
>>>>>>> 3464e05ed4a742d17ca633fde70ffba96f77afc5
else
${OBJECTDIR}/PRINCIPALINT2.o: PRINCIPALINT2.c  .generated_files/flags/default/7c0756e95a6c78b6a388179ef80b0639b0bf8980 .generated_files/flags/default/fd67b544a79261c2fe49714d5749bb13d89b49dc
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PRINCIPALINT2.o.d 
	@${RM} ${OBJECTDIR}/PRINCIPALINT2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PRINCIPALINT2.c  -o ${OBJECTDIR}/PRINCIPALINT2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PRINCIPALINT2.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
>>>>>>> da6c3107aaa705a678b9e6a09de47f9ced63c23a
	
<<<<<<< HEAD
=======
else
${OBJECTDIR}/PRINCIPALLCD.o: PRINCIPALLCD.c  .generated_files/flags/default/741cac56ee23892049bf1077bfec6f7d38c6bf8f .generated_files/flags/default/33ed45b91679709b1183172806be222f11ad8a4f
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PRINCIPALLCD.o.d 
	@${RM} ${OBJECTDIR}/PRINCIPALLCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PRINCIPALLCD.c  -o ${OBJECTDIR}/PRINCIPALLCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PRINCIPALLCD.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/PRINCIPALINT.o: PRINCIPALINT.c  .generated_files/flags/default/8004722eb71a1f3f9205b4584babfa798dcc936f .generated_files/flags/default/33ed45b91679709b1183172806be222f11ad8a4f
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PRINCIPALINT.o.d 
	@${RM} ${OBJECTDIR}/PRINCIPALINT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PRINCIPALINT.c  -o ${OBJECTDIR}/PRINCIPALINT.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/PRINCIPALINT.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
>>>>>>> 3464e05ed4a742d17ca633fde70ffba96f77afc5
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/retardos.o: retardos.s  .generated_files/flags/default/f06eb459c202fc0f0a876bba5a168e63659b4a55 .generated_files/flags/default/33ed45b91679709b1183172806be222f11ad8a4f
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/retardos.o.d 
	@${RM} ${OBJECTDIR}/retardos.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  retardos.s  -o ${OBJECTDIR}/retardos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/retardos.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
<<<<<<< HEAD
${OBJECTDIR}/interrupciones.o: interrupciones.s  .generated_files/flags/default/9f26679001011a714efedcbf1f60350e41a791a9 .generated_files/flags/default/fd67b544a79261c2fe49714d5749bb13d89b49dc
=======
<<<<<<< HEAD
${OBJECTDIR}/LCD.o: LCD.s  .generated_files/flags/default/fc199d5119fdfbea7e240a74aebffad25f67fde7 .generated_files/flags/default/33ed45b91679709b1183172806be222f11ad8a4f
=======
${OBJECTDIR}/LCD.o: LCD.s  .generated_files/flags/default/4209f5a7b9b4b99e0f3aea3b1a5fa56e3c1f3e0c .generated_files/flags/default/fd67b544a79261c2fe49714d5749bb13d89b49dc
>>>>>>> da6c3107aaa705a678b9e6a09de47f9ced63c23a
>>>>>>> 3464e05ed4a742d17ca633fde70ffba96f77afc5
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupciones.o.d 
	@${RM} ${OBJECTDIR}/interrupciones.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  interrupciones.s  -o ${OBJECTDIR}/interrupciones.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/interrupciones.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/LCDg.o: LCDg.s  .generated_files/flags/default/a004169b3de3e92ec94c8bb012541d8314af5dca .generated_files/flags/default/fd67b544a79261c2fe49714d5749bb13d89b49dc
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCDg.o.d 
	@${RM} ${OBJECTDIR}/LCDg.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  LCDg.s  -o ${OBJECTDIR}/LCDg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/LCDg.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/retardos.o: retardos.s  .generated_files/flags/default/845a941e7581417f6df8cddb7a23848e8e4f77a9 .generated_files/flags/default/33ed45b91679709b1183172806be222f11ad8a4f
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/retardos.o.d 
	@${RM} ${OBJECTDIR}/retardos.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  retardos.s  -o ${OBJECTDIR}/retardos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/retardos.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
<<<<<<< HEAD
${OBJECTDIR}/interrupciones.o: interrupciones.s  .generated_files/flags/default/74fb5e7352aab83aff6ade75d175f8147415105d .generated_files/flags/default/fd67b544a79261c2fe49714d5749bb13d89b49dc
=======
<<<<<<< HEAD
${OBJECTDIR}/LCD.o: LCD.s  .generated_files/flags/default/c10c1b093f6e54869ea7eff0e88c0f4f5a789b38 .generated_files/flags/default/33ed45b91679709b1183172806be222f11ad8a4f
=======
${OBJECTDIR}/LCD.o: LCD.s  .generated_files/flags/default/b5b0298767af3b46e1d09a4ecdd3d55818492dcc .generated_files/flags/default/fd67b544a79261c2fe49714d5749bb13d89b49dc
>>>>>>> da6c3107aaa705a678b9e6a09de47f9ced63c23a
>>>>>>> 3464e05ed4a742d17ca633fde70ffba96f77afc5
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupciones.o.d 
	@${RM} ${OBJECTDIR}/interrupciones.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  interrupciones.s  -o ${OBJECTDIR}/interrupciones.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/interrupciones.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/LCDg.o: LCDg.s  .generated_files/flags/default/d1e44e2b5a4a15295186595bdba947d51187bc43 .generated_files/flags/default/fd67b544a79261c2fe49714d5749bb13d89b49dc
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCDg.o.d 
	@${RM} ${OBJECTDIR}/LCDg.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  LCDg.s  -o ${OBJECTDIR}/LCDg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/LCDg.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Ejem1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    p30F3013.gld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/Ejem1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/Ejem1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   p30F3013.gld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/Ejem1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/Ejem1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
