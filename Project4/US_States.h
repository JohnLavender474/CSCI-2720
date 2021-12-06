#pragma once

#include <string>
#include <set>
#include <map>

const std::string AK = "AK";
const std::string AL = "AL";
const std::string AR = "AR";
const std::string AZ = "AZ";
const std::string CA = "CA";

const std::string CO = "CO";
const std::string CT = "CT";
const std::string DE = "DE";
const std::string FL = "FL";
const std::string GA = "GA";

const std::string HI = "HI";
const std::string IA = "IA";
const std::string ID = "ID";
const std::string IL = "IL";
const std::string IN = "IN";

const std::string KS = "KS";
const std::string KY = "KY";
const std::string LA = "LA";
const std::string MA = "MA";
const std::string MD = "MD";

const std::string ME = "ME";
const std::string MI = "MI";
const std::string MN = "MN";
const std::string MO = "MO";
const std::string MS = "MS";

const std::string MT = "MT";
const std::string NC = "NC";
const std::string ND = "ND";
const std::string NE = "NE";
const std::string NH = "NH";

const std::string NJ = "NJ";
const std::string NM = "NM";
const std::string NV = "NV";
const std::string NY = "NY";
const std::string OH = "OH";

const std::string OK = "OK";
const std::string OR = "OR";
const std::string PA = "PA";
const std::string RI = "RI";
const std::string SC = "SC";

const std::string SD = "SD";
const std::string TN = "TN";
const std::string TX = "TX";
const std::string UT = "UT";
const std::string VA = "VA";

const std::string VT = "VT";
const std::string WA = "WA";
const std::string WI = "WI";
const std::string WV = "WV";
const std::string WY = "WY";

std::map<std::string, std::set<std::string>> us_state_adjacencies =
		{
				{AK, {}},
				{AL, {MS, TN, GA, FL}},
				{AR, {MO, TN, MS, LA, TX, OK}},
				{AZ, {CA, NV, UT, CO, NM}},
				{CA, {OR, NV, AZ}},
				
				{CO, {WY, NE, KS, OK, NM, AZ, UT}},
				{CT, {NY, MA, RI}},
				{DE, {MD, PA, NJ}},
				{FL, {AL, GA}},
				{GA, {FL, AL, TN, NC, SC}},
				
				{HI, {}},
				{IA, {MN, WI, IL, MO, NE, SD}},
				{ID, {MT, WY, UT, NV, OR, WA}},
				{IL, {IN, KY, MO, IA, WI}},
				{IN, {MI, OH, KY, IL}},
				
				{KS, {NE, MO, OK, CO}},
				{KY, {IN, OH, WV, VA, TN, MO, IL}},
				{LA, {TX, AR, MS}},
				{MA, {RI, CT, NY, NH, VT}},
				{MD, {VA, WV, PA, DE}},
				
				{ME, {NH}},
				{MI, {WI, IN, OH}},
				{MN, {WI, IA, SD, ND}},
				{MO, {IA, IL, KY, TN, AR, OK, KS, NE}},
				{MS, {LA, AR, TN, AL}},
				
				{MT, {ND, SD, WY, ID}},
				{NC, {VA, TN, GA, SC}},
				{ND, {MN, SD, MT}},
				{NE, {SD, IA, MO, KS, CO, WY}},
				{NH, {VT, ME, MA}},
				
				{NJ, {DE, PA, NY}},
				{NM, {AZ, UT, CO, OK, TX}},
				{NV, {ID, UT, AZ, CA, OR}},
				{NY, {NJ, PA, VT, MA, CT}},
				{OH, {PA, WV, KY, IN, MI}},
				
				{OK, {KS, MO, AR, TX, NM, CO}},
				{OR, {CA, NV, ID, WA}},
				{PA, {NY, NJ, DE, MD, WV, OH}},
				{RI, {CT, MA}},
				{SC, {GA, NC}},
				
				{SD, {ND, MN, IA, NE, WY, MT}},
				{TN, {KY, VA, NC, GA, AL, MS, AR, MO}},
				{TX, {NM, OK, AR, LA}},
				{UT, {ID, WY, CO, NM, AZ, NV}},
				{VA, {NC, TN, KY, WV, MD}},
				
				{VT, {NY, NH, MA}},
				{WA, {ID, OR}},
				{WI, {MI, MN, IA, IL}},
				{WV, {OH, PA, MD, VA, KY}},
				{WY, {MT, SD, NE, CO, UT, ID}}
		};