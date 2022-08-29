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
FINAL_IMAGE=${DISTDIR}/INT.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/INT.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=LCDg.s retardos.s ../../Proyecto/Sensores/sensoresINT.s ../../Proyecto/Motores/MOTORISR.s ../../Proyecto/ProyectoPrincipal.c ../../Proyecto/UART/ISRUART.s

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/LCDg.o ${OBJECTDIR}/retardos.o ${OBJECTDIR}/_ext/637208046/sensoresINT.o ${OBJECTDIR}/_ext/1867272583/MOTORISR.o ${OBJECTDIR}/_ext/2096860475/ProyectoPrincipal.o ${OBJECTDIR}/_ext/1696894248/ISRUART.o
POSSIBLE_DEPFILES=${OBJECTDIR}/LCDg.o.d ${OBJECTDIR}/retardos.o.d ${OBJECTDIR}/_ext/637208046/sensoresINT.o.d ${OBJECTDIR}/_ext/1867272583/MOTORISR.o.d ${OBJECTDIR}/_ext/2096860475/ProyectoPrincipal.o.d ${OBJECTDIR}/_ext/1696894248/ISRUART.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/LCDg.o ${OBJECTDIR}/retardos.o ${OBJECTDIR}/_ext/637208046/sensoresINT.o ${OBJECTDIR}/_ext/1867272583/MOTORISR.o ${OBJECTDIR}/_ext/2096860475/ProyectoPrincipal.o ${OBJECTDIR}/_ext/1696894248/ISRUART.o

# Source Files
SOURCEFILES=LCDg.s retardos.s ../../Proyecto/Sensores/sensoresINT.s ../../Proyecto/Motores/MOTORISR.s ../../Proyecto/ProyectoPrincipal.c ../../Proyecto/UART/ISRUART.s



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/INT.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=30F3013
MP_LINKER_FILE_OPTION=,--script="p30F3013.gld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/2096860475/ProyectoPrincipal.o: ../../Proyecto/ProyectoPrincipal.c  .generated_files/flags/default/a244dd8209a4c92d3f153dc8e662cd886640d5b0 .generated_files/flags/default/33ed45b91679709b1183172806be222f11ad8a4f
	@${MKDIR} "${OBJECTDIR}/_ext/2096860475" 
	@${RM} ${OBJECTDIR}/_ext/2096860475/ProyectoPrincipal.o.d 
	@${RM} ${OBJECTDIR}/_ext/2096860475/ProyectoPrincipal.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../Proyecto/ProyectoPrincipal.c  -o ${OBJECTDIR}/_ext/2096860475/ProyectoPrincipal.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2096860475/ProyectoPrincipal.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/_ext/2096860475/ProyectoPrincipal.o: ../../Proyecto/ProyectoPrincipal.c  .generated_files/flags/default/c500db47c30ac4f5b101655deccffa2209dcece1 .generated_files/flags/default/33ed45b91679709b1183172806be222f11ad8a4f
	@${MKDIR} "${OBJECTDIR}/_ext/2096860475" 
	@${RM} ${OBJECTDIR}/_ext/2096860475/ProyectoPrincipal.o.d 
	@${RM} ${OBJECTDIR}/_ext/2096860475/ProyectoPrincipal.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../Proyecto/ProyectoPrincipal.c  -o ${OBJECTDIR}/_ext/2096860475/ProyectoPrincipal.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2096860475/ProyectoPrincipal.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/LCDg.o: LCDg.s  .generated_files/flags/default/526a2904bda1ffa181eccbcbf21fb2f2a4cc7644 .generated_files/flags/default/33ed45b91679709b1183172806be222f11ad8a4f
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCDg.o.d 
	@${RM} ${OBJECTDIR}/LCDg.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  LCDg.s  -o ${OBJECTDIR}/LCDg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/LCDg.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/retardos.o: retardos.s  .generated_files/flags/default/1a6f5d1f656be03423c18cdc742234cb0774759e .generated_files/flags/default/33ed45b91679709b1183172806be222f11ad8a4f
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/retardos.o.d 
	@${RM} ${OBJECTDIR}/retardos.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  retardos.s  -o ${OBJECTDIR}/retardos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/retardos.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/637208046/sensoresINT.o: ../../Proyecto/Sensores/sensoresINT.s  .generated_files/flags/default/349ad2b51d57bd5baa4565182f5dc312d3241b16 .generated_files/flags/default/33ed45b91679709b1183172806be222f11ad8a4f
	@${MKDIR} "${OBJECTDIR}/_ext/637208046" 
	@${RM} ${OBJECTDIR}/_ext/637208046/sensoresINT.o.d 
	@${RM} ${OBJECTDIR}/_ext/637208046/sensoresINT.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../../Proyecto/Sensores/sensoresINT.s  -o ${OBJECTDIR}/_ext/637208046/sensoresINT.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/_ext/637208046/sensoresINT.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1867272583/MOTORISR.o: ../../Proyecto/Motores/MOTORISR.s  .generated_files/flags/default/bf1b48dab04876b0927b6eda7b4ffd5213c7d8b7 .generated_files/flags/default/33ed45b91679709b1183172806be222f11ad8a4f
	@${MKDIR} "${OBJECTDIR}/_ext/1867272583" 
	@${RM} ${OBJECTDIR}/_ext/1867272583/MOTORISR.o.d 
	@${RM} ${OBJECTDIR}/_ext/1867272583/MOTORISR.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../../Proyecto/Motores/MOTORISR.s  -o ${OBJECTDIR}/_ext/1867272583/MOTORISR.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/_ext/1867272583/MOTORISR.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1696894248/ISRUART.o: ../../Proyecto/UART/ISRUART.s  .generated_files/flags/default/1ee9044883044ab7a7629a5a5d277402c8a7b579 .generated_files/flags/default/33ed45b91679709b1183172806be222f11ad8a4f
	@${MKDIR} "${OBJECTDIR}/_ext/1696894248" 
	@${RM} ${OBJECTDIR}/_ext/1696894248/ISRUART.o.d 
	@${RM} ${OBJECTDIR}/_ext/1696894248/ISRUART.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../../Proyecto/UART/ISRUART.s  -o ${OBJECTDIR}/_ext/1696894248/ISRUART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/_ext/1696894248/ISRUART.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/LCDg.o: LCDg.s  .generated_files/flags/default/a4dde6ade40ce1606acc623a0d2fa1ba4cd2f7bc .generated_files/flags/default/33ed45b91679709b1183172806be222f11ad8a4f
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCDg.o.d 
	@${RM} ${OBJECTDIR}/LCDg.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  LCDg.s  -o ${OBJECTDIR}/LCDg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/LCDg.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/retardos.o: retardos.s  .generated_files/flags/default/5b579282dbf5ef337600f9c01556288cee5dacea .generated_files/flags/default/33ed45b91679709b1183172806be222f11ad8a4f
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/retardos.o.d 
	@${RM} ${OBJECTDIR}/retardos.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  retardos.s  -o ${OBJECTDIR}/retardos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/retardos.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/637208046/sensoresINT.o: ../../Proyecto/Sensores/sensoresINT.s  .generated_files/flags/default/4ab6cc6ab65a80b80b681bbf3796fbded4f0e482 .generated_files/flags/default/33ed45b91679709b1183172806be222f11ad8a4f
	@${MKDIR} "${OBJECTDIR}/_ext/637208046" 
	@${RM} ${OBJECTDIR}/_ext/637208046/sensoresINT.o.d 
	@${RM} ${OBJECTDIR}/_ext/637208046/sensoresINT.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../../Proyecto/Sensores/sensoresINT.s  -o ${OBJECTDIR}/_ext/637208046/sensoresINT.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/_ext/637208046/sensoresINT.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1867272583/MOTORISR.o: ../../Proyecto/Motores/MOTORISR.s  .generated_files/flags/default/2c0f2dd34e83c812d4970cd4bf397f581abb1d46 .generated_files/flags/default/33ed45b91679709b1183172806be222f11ad8a4f
	@${MKDIR} "${OBJECTDIR}/_ext/1867272583" 
	@${RM} ${OBJECTDIR}/_ext/1867272583/MOTORISR.o.d 
	@${RM} ${OBJECTDIR}/_ext/1867272583/MOTORISR.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../../Proyecto/Motores/MOTORISR.s  -o ${OBJECTDIR}/_ext/1867272583/MOTORISR.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/_ext/1867272583/MOTORISR.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1696894248/ISRUART.o: ../../Proyecto/UART/ISRUART.s  .generated_files/flags/default/22b80dcc3de4b50d74bc30b4e91c3d803d1326ff .generated_files/flags/default/33ed45b91679709b1183172806be222f11ad8a4f
	@${MKDIR} "${OBJECTDIR}/_ext/1696894248" 
	@${RM} ${OBJECTDIR}/_ext/1696894248/ISRUART.o.d 
	@${RM} ${OBJECTDIR}/_ext/1696894248/ISRUART.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../../Proyecto/UART/ISRUART.s  -o ${OBJECTDIR}/_ext/1696894248/ISRUART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/_ext/1696894248/ISRUART.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/INT.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    p30F3013.gld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/INT.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/INT.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   p30F3013.gld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/INT.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/INT.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
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
