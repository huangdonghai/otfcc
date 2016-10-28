#ifndef CARYLL_INCLUDE_TABLE_GASP_H
#define CARYLL_INCLUDE_TABLE_GASP_H

#include "table-common.h"

typedef struct {
	uint16_t rangeMaxPPEM;
	bool dogray;
	bool gridfit;
	bool symmetric_smoothing;
	bool symmetric_gridfit;
} gasp_Record;
typedef struct {
	uint16_t version;
	uint16_t numRanges;
	gasp_Record *records;
} table_gasp;

table_gasp *otfcc_newGasp();
void otfcc_deleteGasp(table_gasp *table);
table_gasp *otfcc_readGasp(const otfcc_Packet packet, const otfcc_Options *options);
void otfcc_dumpGasp(const table_gasp *table, json_value *root, const otfcc_Options *options);
table_gasp *otfcc_parseGasp(const json_value *root, const otfcc_Options *options);
caryll_Buffer *otfcc_buildGasp(const table_gasp *table, const otfcc_Options *options);
#endif