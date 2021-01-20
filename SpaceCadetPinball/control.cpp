#include "pch.h"
#include "control.h"

#include "objlist_class.h"
#include "pb.h"
#include "TBlocker.h"
#include "TBumper.h"
#include "TLight.h"
#include "TLightGroup.h"
#include "TPinballTable.h"
#include "TSink.h"
#include "TSound.h"

int control::pbctrl_state;

int control_bump_scores1[] = {500, 1000, 1500, 2000};
int control_roll_scores1[] = {2000};
int control_bump_scores2[] = {1500, 2500, 3500, 4500};
int control_roll_scores2[] = {500};
int control_rebo_score1[] = {500};
int control_oneway4_score1[6] = {15000, 30000, 75000, 30000, 15000, 7500};
int control_ramp_score1[1] = {5000};
int control_roll_score1[1] = {20000};
int control_roll_score2[2] = {5000, 25000};
int control_roll_score3[1] = {10000};
int control_roll_score4[1] = {500};
int control_flag_score1[2] = {500, 2500};
int control_kickout_score1[5] = {10000, 0, 20000, 50000, 150000};
int control_sink_score1[3] = {2500, 5000, 7500};
int control_target_score1[2] = {500, 5000};
int control_target_score2[3] = {1500, 10000, 50000};
int control_target_score3[2] = {500, 1500};
int control_target_score4[1] = {750};
int control_target_score5[1] = {1000};
int control_target_score6[1] = {750};
int control_target_score7[1] = {750};
int control_roll_score5[1] = {10000};
int control_kickout_score2[1] = {20000};
int control_kickout_score3[1] = {50000};


component_tag control_attack_bump_tag = {"attack_bumpers", nullptr};
component_tag control_block1_tag = {"v_bloc1", nullptr};
component_tag control_bmpr_inc_lights_tag = {"bmpr_inc_lights", nullptr};
component_tag control_bpr_solotgt_lights_tag = {"bpr_solotgt_lights", nullptr};
component_tag control_bsink_arrow_lights_tag = {"bsink_arrow_lights", nullptr};
component_tag control_bumber_target_lights_tag = {"bumper_target_lights", nullptr};
component_tag control_bump1_tag = {"a_bump1", nullptr};
component_tag control_bump2_tag = {"a_bump2", nullptr};
component_tag control_bump3_tag = {"a_bump3", nullptr};
component_tag control_bump4_tag = {"a_bump4", nullptr};
component_tag control_bump5_tag = {"a_bump5", nullptr};
component_tag control_bump6_tag = {"a_bump6", nullptr};
component_tag control_bump7_tag = {"a_bump7", nullptr};
component_tag control_drain_tag = {"drain", nullptr};
component_tag control_flag1_tag = {"a_flag1", nullptr};
component_tag control_flag2_tag = {"a_flag2", nullptr};
component_tag control_flip1_tag = {"a_flip1", nullptr};
component_tag control_flip2_tag = {"a_flip2", nullptr};
component_tag control_fuel_bargraph_tag = {"fuel_bargraph", nullptr};
component_tag control_gate1_tag = {"v_gate1", nullptr};
component_tag control_gate2_tag = {"v_gate2", nullptr};
component_tag control_goal_lights_tag = {"goal_lights", nullptr};
component_tag control_hyper_lights_tag = {"hyperspace_lights", nullptr};
component_tag control_info_text_box_tag = {"info_text_box", nullptr};
component_tag control_kicker1_tag = {"a_kick1", nullptr};
component_tag control_kicker2_tag = {"a_kick2", nullptr};
component_tag control_kickout1_tag = {"a_kout1", nullptr};
component_tag control_kickout2_tag = {"a_kout2", nullptr};
component_tag control_kickout3_tag = {"a_kout3", nullptr};
component_tag control_l_trek_lights_tag = {"l_trek_lights", nullptr};
component_tag control_launch_bump_tag = {"launch_bumpers", nullptr};
component_tag control_lchute_tgt_lights_tag = {"lchute_tgt_lights", nullptr};
component_tag control_lite1_tag = {"lite1", nullptr};
component_tag control_lite2_tag = {"lite2", nullptr};
component_tag control_lite3_tag = {"lite3", nullptr};
component_tag control_lite4_tag = {"lite4", nullptr};
component_tag control_lite5_tag = {"lite5", nullptr};
component_tag control_lite6_tag = {"lite6", nullptr};
component_tag control_lite7_tag = {"lite7", nullptr};
component_tag control_lite8_tag = {"lite8", nullptr};
component_tag control_lite9_tag = {"lite9", nullptr};
component_tag control_lite10_tag = {"lite10", nullptr};
component_tag control_lite11_tag = {"lite11", nullptr};
component_tag control_lite12_tag = {"lite12", nullptr};
component_tag control_lite13_tag = {"lite13", nullptr};
component_tag control_lite16_tag = {"lite16", nullptr};
component_tag control_lite17_tag = {"lite17", nullptr};
component_tag control_lite18_tag = {"lite18", nullptr};
component_tag control_lite19_tag = {"lite19", nullptr};
component_tag control_lite20_tag = {"lite20", nullptr};
component_tag control_lite21_tag = {"lite21", nullptr};
component_tag control_lite22_tag = {"lite22", nullptr};
component_tag control_lite23_tag = {"lite23", nullptr};
component_tag control_lite24_tag = {"lite24", nullptr};
component_tag control_lite25_tag = {"lite25", nullptr};
component_tag control_lite26_tag = {"lite26", nullptr};
component_tag control_lite27_tag = {"lite27", nullptr};
component_tag control_lite28_tag = {"lite28", nullptr};
component_tag control_lite29_tag = {"lite29", nullptr};
component_tag control_lite30_tag = {"lite30", nullptr};
component_tag control_lite54_tag = {"lite54", nullptr};
component_tag control_lite55_tag = {"lite55", nullptr};
component_tag control_lite56_tag = {"lite56", nullptr};
component_tag control_lite58_tag = {"lite58", nullptr};
component_tag control_lite59_tag = {"lite59", nullptr};
component_tag control_lite60_tag = {"lite60", nullptr};
component_tag control_lite61_tag = {"lite61", nullptr};
component_tag control_lite62_tag = {"lite62", nullptr};
component_tag control_lite67_tag = {"lite67", nullptr};
component_tag control_lite68_tag = {"lite68", nullptr};
component_tag control_lite69_tag = {"lite69", nullptr};
component_tag control_lite70_tag = {"lite70", nullptr};
component_tag control_lite71_tag = {"lite71", nullptr};
component_tag control_lite72_tag = {"lite72", nullptr};
component_tag control_lite77_tag = {"lite77", nullptr};
component_tag control_lite84_tag = {"lite84", nullptr};
component_tag control_lite85_tag = {"lite85", nullptr};
component_tag control_lite101_tag = {"lite101", nullptr};
component_tag control_lite102_tag = {"lite102", nullptr};
component_tag control_lite103_tag = {"lite103", nullptr};
component_tag control_lite104_tag = {"lite104", nullptr};
component_tag control_lite105_tag = {"lite105", nullptr};
component_tag control_lite106_tag = {"lite106", nullptr};
component_tag control_lite107_tag = {"lite107", nullptr};
component_tag control_lite108_tag = {"lite108", nullptr};
component_tag control_lite109_tag = {"lite109", nullptr};
component_tag control_lite110_tag = {"lite110", nullptr};
component_tag control_lite130_tag = {"lite130", nullptr};
component_tag control_lite131_tag = {"lite131", nullptr};
component_tag control_lite132_tag = {"lite132", nullptr};
component_tag control_lite133_tag = {"lite133", nullptr};
component_tag control_lite169_tag = {"lite169", nullptr};
component_tag control_lite170_tag = {"lite170", nullptr};
component_tag control_lite171_tag = {"lite171", nullptr};
component_tag control_lite195_tag = {"lite195", nullptr};
component_tag control_lite196_tag = {"lite196", nullptr};
component_tag control_lite198_tag = {"lite198", nullptr};
component_tag control_lite199_tag = {"lite199", nullptr};
component_tag control_lite200_tag = {"lite200", nullptr};
component_tag control_lite300_tag = {"lite300", nullptr};
component_tag control_lite301_tag = {"lite301", nullptr};
component_tag control_lite302_tag = {"lite302", nullptr};
component_tag control_lite303_tag = {"lite303", nullptr};
component_tag control_lite304_tag = {"lite304", nullptr};
component_tag control_lite305_tag = {"lite305", nullptr};
component_tag control_lite306_tag = {"lite306", nullptr};
component_tag control_lite307_tag = {"lite307", nullptr};
component_tag control_lite308_tag = {"lite308", nullptr};
component_tag control_lite309_tag = {"lite309", nullptr};
component_tag control_lite310_tag = {"lite310", nullptr};
component_tag control_lite311_tag = {"lite311", nullptr};
component_tag control_lite312_tag = {"lite312", nullptr};
component_tag control_lite313_tag = {"lite313", nullptr};
component_tag control_lite314_tag = {"lite314", nullptr};
component_tag control_lite315_tag = {"lite315", nullptr};
component_tag control_lite316_tag = {"lite316", nullptr};
component_tag control_lite317_tag = {"lite317", nullptr};
component_tag control_lite318_tag = {"lite318", nullptr};
component_tag control_lite319_tag = {"lite319", nullptr};
component_tag control_lite320_tag = {"lite320", nullptr};
component_tag control_lite321_tag = {"lite321", nullptr};
component_tag control_lite322_tag = {"lite322", nullptr};
component_tag control_literoll179_tag = {"literoll179", nullptr};
component_tag control_literoll180_tag = {"literoll180", nullptr};
component_tag control_literoll181_tag = {"literoll181", nullptr};
component_tag control_literoll182_tag = {"literoll182", nullptr};
component_tag control_literoll183_tag = {"literoll183", nullptr};
component_tag control_literoll184_tag = {"literoll184", nullptr};
component_tag control_middle_circle_tag = {"middle_circle", nullptr};
component_tag control_mission_text_box_tag = {"mission_text_box", nullptr};
component_tag control_oneway1_tag = {"s_onewy1", nullptr};
component_tag control_oneway4_tag = {"s_onewy4", nullptr};
component_tag control_oneway10_tag = {"s_onewy10", nullptr};
component_tag control_outer_circle_tag = {"outer_circle", nullptr};
component_tag control_plunger_tag = {"plunger", nullptr};
component_tag control_r_trek_lights_tag = {"r_trek_lights", nullptr};
component_tag control_ramp_bmpr_inc_lights_tag = {"ramp_bmpr_inc_lights", nullptr};
component_tag control_ramp_hole_tag = {"ramp_hole", nullptr};
component_tag control_ramp_tag = {"ramp", nullptr};
component_tag control_ramp_tgt_lights_tag = {"ramp_tgt_lights", nullptr};
component_tag control_rebo1_tag = {"v_rebo1", nullptr};
component_tag control_rebo2_tag = {"v_rebo2", nullptr};
component_tag control_rebo3_tag = {"v_rebo3", nullptr};
component_tag control_rebo4_tag = {"v_rebo4", nullptr};
component_tag control_roll1_tag = {"a_roll1", nullptr};
component_tag control_roll2_tag = {"a_roll2", nullptr};
component_tag control_roll3_tag = {"a_roll3", nullptr};
component_tag control_roll4_tag = {"a_roll4", nullptr};
component_tag control_roll5_tag = {"a_roll5", nullptr};
component_tag control_roll6_tag = {"a_roll6", nullptr};
component_tag control_roll7_tag = {"a_roll7", nullptr};
component_tag control_roll8_tag = {"a_roll8", nullptr};
component_tag control_roll9_tag = {"a_roll9", nullptr};
component_tag control_roll110_tag = {"a_roll110", nullptr};
component_tag control_roll111_tag = {"a_roll111", nullptr};
component_tag control_roll112_tag = {"a_roll112", nullptr};
component_tag control_roll179_tag = {"a_roll179", nullptr};
component_tag control_roll180_tag = {"a_roll180", nullptr};
component_tag control_roll181_tag = {"a_roll181", nullptr};
component_tag control_roll182_tag = {"a_roll182", nullptr};
component_tag control_roll183_tag = {"a_roll183", nullptr};
component_tag control_roll184_tag = {"a_roll184", nullptr};
component_tag control_sink1_tag = {"v_sink1", nullptr};
component_tag control_sink2_tag = {"v_sink2", nullptr};
component_tag control_sink3_tag = {"v_sink3", nullptr};
component_tag control_sink7_tag = {"v_sink7", nullptr};
component_tag control_skill_shot_lights_tag = {"skill_shot_lights", nullptr};
component_tag control_soundwave3_tag = {"soundwave3", nullptr};
component_tag control_soundwave7_tag = {"soundwave7", nullptr};
component_tag control_soundwave8_tag = {"soundwave8", nullptr};
component_tag control_soundwave9_tag = {"soundwave9", nullptr};
component_tag control_soundwave10_tag = {"soundwave10", nullptr};
component_tag control_soundwave14_1_tag = {"soundwave14", nullptr};
component_tag control_soundwave14_2_tag = {"soundwave14", nullptr};
component_tag control_soundwave21_tag = {"soundwave21", nullptr};
component_tag control_soundwave23_tag = {"soundwave23", nullptr};
component_tag control_soundwave24_tag = {"soundwave24", nullptr};
component_tag control_soundwave25_tag = {"soundwave25", nullptr};
component_tag control_soundwave26_tag = {"soundwave26", nullptr};
component_tag control_soundwave27_tag = {"soundwave27", nullptr};
component_tag control_soundwave28_tag = {"soundwave28", nullptr};
component_tag control_soundwave30_tag = {"soundwave30", nullptr};
component_tag control_soundwave35_1_tag = {"soundwave35", nullptr};
component_tag control_soundwave35_2_tag = {"soundwave35", nullptr};
component_tag control_soundwave36_1_tag = {"soundwave36", nullptr};
component_tag control_soundwave36_2_tag = {"soundwave36", nullptr};
component_tag control_soundwave38_tag = {"soundwave38", nullptr};
component_tag control_soundwave39_tag = {"soundwave39", nullptr};
component_tag control_soundwave40_tag = {"soundwave40", nullptr};
component_tag control_soundwave41_tag = {"soundwave41", nullptr};
component_tag control_soundwave44_tag = {"soundwave44", nullptr};
component_tag control_soundwave45_tag = {"soundwave45", nullptr};
component_tag control_soundwave46_tag = {"soundwave46", nullptr};
component_tag control_soundwave47_tag = {"soundwave47", nullptr};
component_tag control_soundwave48_tag = {"soundwave48", nullptr};
component_tag control_soundwave49D_tag = {"soundwave49D", nullptr};
component_tag control_soundwave50_1_tag = {"soundwave50", nullptr};
component_tag control_soundwave50_2_tag = {"soundwave50", nullptr};
component_tag control_soundwave52_tag = {"soundwave52", nullptr};
component_tag control_soundwave59_tag = {"soundwave59", nullptr};
component_tag control_target1_tag = {"a_targ1", nullptr};
component_tag control_target2_tag = {"a_targ2", nullptr};
component_tag control_target3_tag = {"a_targ3", nullptr};
component_tag control_target4_tag = {"a_targ4", nullptr};
component_tag control_target5_tag = {"a_targ5", nullptr};
component_tag control_target6_tag = {"a_targ6", nullptr};
component_tag control_target7_tag = {"a_targ7", nullptr};
component_tag control_target8_tag = {"a_targ8", nullptr};
component_tag control_target9_tag = {"a_targ9", nullptr};
component_tag control_target10_tag = {"a_targ10", nullptr};
component_tag control_target11_tag = {"a_targ11", nullptr};
component_tag control_target12_tag = {"a_targ12", nullptr};
component_tag control_target13_tag = {"a_targ13", nullptr};
component_tag control_target14_tag = {"a_targ14", nullptr};
component_tag control_target15_tag = {"a_targ15", nullptr};
component_tag control_target16_tag = {"a_targ16", nullptr};
component_tag control_target17_tag = {"a_targ17", nullptr};
component_tag control_target18_tag = {"a_targ18", nullptr};
component_tag control_target19_tag = {"a_targ19", nullptr};
component_tag control_target20_tag = {"a_targ20", nullptr};
component_tag control_target21_tag = {"a_targ21", nullptr};
component_tag control_target22_tag = {"a_targ22", nullptr};
component_tag control_top_circle_tgt_lights_tag = {"top_circle_tgt_lights", nullptr};
component_tag control_top_target_lights_tag = {"top_target_lights", nullptr};
component_tag control_trip1_tag = {"s_trip1", nullptr};
component_tag control_trip2_tag = {"s_trip2", nullptr};
component_tag control_trip3_tag = {"s_trip3", nullptr};
component_tag control_trip4_tag = {"s_trip4", nullptr};
component_tag control_trip5_tag = {"s_trip5", nullptr};
component_tag control_worm_hole_lights_tag = {"worm_hole_lights", nullptr};


TPinballTable* control::TableG;
component_info control::score_components[88]
{
	component_info{&control_bump1_tag, {BumperControl, 4, control_bump_scores1}},
	component_info{&control_bump2_tag, {BumperControl, 4, control_bump_scores1}},
	component_info{&control_bump3_tag, {BumperControl, 4, control_bump_scores1}},
	component_info{&control_bump4_tag, {BumperControl, 4, control_bump_scores1}},
	component_info{&control_roll3_tag, {ReentryLanesRolloverControl, 1, control_roll_scores1}},
	component_info{&control_roll2_tag, {ReentryLanesRolloverControl, 1, control_roll_scores1}},
	component_info{&control_roll1_tag, {ReentryLanesRolloverControl, 1, control_roll_scores1}},
	component_info{&control_attack_bump_tag, {BumperGroupControl, 0, nullptr}},
	component_info{&control_bump5_tag, {BumperControl, 4, control_bump_scores2}},
	component_info{&control_bump6_tag, {BumperControl, 4, control_bump_scores2}},
	component_info{&control_bump7_tag, {BumperControl, 4, control_bump_scores2}},
	component_info{&control_roll112_tag, {LaunchLanesRolloverControl, 1, control_roll_scores2}},
	component_info{&control_roll111_tag, {LaunchLanesRolloverControl, 1, control_roll_scores2}},
	component_info{&control_roll110_tag, {LaunchLanesRolloverControl, 1, control_roll_scores2}},
	component_info{&control_launch_bump_tag, {BumperGroupControl, 0, nullptr}},
	component_info{&control_rebo1_tag, {FlipperRebounderControl1, 1, control_rebo_score1}},
	component_info{&control_rebo2_tag, {FlipperRebounderControl2, 1, control_rebo_score1}},
	component_info{&control_rebo3_tag, {RebounderControl, 1, control_rebo_score1}},
	component_info{&control_rebo4_tag, {RebounderControl, 1, control_rebo_score1}},
	component_info{&control_kicker1_tag, {LeftKickerControl, 0, nullptr}},
	component_info{&control_kicker2_tag, {RightKickerControl, 0, nullptr}},
	component_info{&control_gate1_tag, {LeftKickerGateControl, 0, nullptr}},
	component_info{&control_gate2_tag, {RightKickerGateControl, 0, nullptr}},
	component_info{&control_oneway4_tag, {DeploymentChuteToEscapeChuteOneWayControl, 6, control_oneway4_score1}},
	component_info{&control_oneway10_tag, {DeploymentChuteToTableOneWayControl, 0, nullptr}},
	component_info{&control_block1_tag, {DrainBallBlockerControl, 0, nullptr}},
	component_info{&control_ramp_tag, {LaunchRampControl, 1, control_ramp_score1}},
	component_info{&control_ramp_hole_tag, {LaunchRampHoleControl, 0, nullptr}},
	component_info{&control_roll4_tag, {OutLaneRolloverControl, 1, control_roll_score1}},
	component_info{&control_roll8_tag, {OutLaneRolloverControl, 1, control_roll_score1}},
	component_info{&control_lite17_tag, {ExtraBallLightControl, 0, nullptr}},
	component_info{&control_roll6_tag, {ReturnLaneRolloverControl, 2, control_roll_score2}},
	component_info{&control_roll7_tag, {ReturnLaneRolloverControl, 2, control_roll_score2}},
	component_info{&control_roll5_tag, {BonusLaneRolloverControl, 1, control_roll_score3}},
	component_info{&control_roll179_tag, {FuelRollover1Control, 1, control_roll_score4}},
	component_info{&control_roll180_tag, {FuelRollover2Control, 1, control_roll_score4}},
	component_info{&control_roll181_tag, {FuelRollover3Control, 1, control_roll_score4}},
	component_info{&control_roll182_tag, {FuelRollover4Control, 1, control_roll_score4}},
	component_info{&control_roll183_tag, {FuelRollover5Control, 1, control_roll_score4}},
	component_info{&control_roll184_tag, {FuelRollover6Control, 1, control_roll_score4}},
	component_info{&control_flag1_tag, {FlagControl, 2, control_flag_score1}},
	component_info{&control_kickout2_tag, {HyperspaceKickOutControl, 5, control_kickout_score1}},
	component_info{&control_hyper_lights_tag, {HyperspaceLightGroupControl, 0, nullptr}},
	component_info{&control_flag2_tag, {FlagControl, 2, control_flag_score1}},
	component_info{&control_sink1_tag, {WormHoleControl, 3, control_sink_score1}},
	component_info{&control_sink2_tag, {WormHoleControl, 3, control_sink_score1}},
	component_info{&control_sink3_tag, {WormHoleControl, 3, control_sink_score1}},
	component_info{&control_flip1_tag, {LeftFlipperControl, 0, nullptr}},
	component_info{&control_flip2_tag, {RightFlipperControl, 0, nullptr}},
	component_info{&control_plunger_tag, {PlungerControl, 0, nullptr}},
	component_info{&control_target1_tag, {BoosterTargetControl, 2, control_target_score1}},
	component_info{&control_target2_tag, {BoosterTargetControl, 2, control_target_score1}},
	component_info{&control_target3_tag, {BoosterTargetControl, 2, control_target_score1}},
	component_info{&control_lite60_tag, {JackpotLightControl, 0, nullptr}},
	component_info{&control_lite59_tag, {BonusLightControl, 0, nullptr}},
	component_info{&control_target6_tag, {MedalTargetControl, 3, control_target_score2}},
	component_info{&control_target5_tag, {MedalTargetControl, 3, control_target_score2}},
	component_info{&control_target4_tag, {MedalTargetControl, 3, control_target_score2}},
	component_info{&control_bumber_target_lights_tag, {MedalLightGroupControl, 0, nullptr}},
	component_info{&control_target9_tag, {MultiplierTargetControl, 2, control_target_score3}},
	component_info{&control_target8_tag, {MultiplierTargetControl, 2, control_target_score3}},
	component_info{&control_target7_tag, {MultiplierTargetControl, 2, control_target_score3}},
	component_info{&control_top_target_lights_tag, {MultiplierLightGroupControl, 0, nullptr}},
	component_info{&control_target10_tag, {FuelSpotTargetControl, 1, control_target_score4}},
	component_info{&control_target11_tag, {FuelSpotTargetControl, 1, control_target_score4}},
	component_info{&control_target12_tag, {FuelSpotTargetControl, 1, control_target_score4}},
	component_info{&control_target13_tag, {MissionSpotTargetControl, 1, control_target_score5}},
	component_info{&control_target14_tag, {MissionSpotTargetControl, 1, control_target_score5}},
	component_info{&control_target15_tag, {MissionSpotTargetControl, 1, control_target_score5}},
	component_info{&control_target16_tag, {LeftHazardSpotTargetControl, 1, control_target_score6}},
	component_info{&control_target17_tag, {LeftHazardSpotTargetControl, 1, control_target_score6}},
	component_info{&control_target18_tag, {LeftHazardSpotTargetControl, 1, control_target_score6}},
	component_info{&control_target19_tag, {RightHazardSpotTargetControl, 1, control_target_score6}},
	component_info{&control_target20_tag, {RightHazardSpotTargetControl, 1, control_target_score6}},
	component_info{&control_target21_tag, {RightHazardSpotTargetControl, 1, control_target_score6}},
	component_info{&control_target22_tag, {WormHoleDestinationControl, 1, control_target_score7}},
	component_info{&control_roll9_tag, {SpaceWarpRolloverControl, 1, control_roll_score5}},
	component_info{&control_kickout3_tag, {BlackHoleKickoutControl, 1, control_kickout_score2}},
	component_info{&control_kickout1_tag, {GravityWellKickoutControl, 1, control_kickout_score3}},
	component_info{&control_drain_tag, {BallDrainControl, 0, nullptr}},
	component_info{&control_oneway1_tag, {SkillShotGate1Control, 0, nullptr}},
	component_info{&control_trip1_tag, {SkillShotGate2Control, 0, nullptr}},
	component_info{&control_trip2_tag, {SkillShotGate3Control, 0, nullptr}},
	component_info{&control_trip3_tag, {SkillShotGate4Control, 0, nullptr}},
	component_info{&control_trip4_tag, {SkillShotGate5Control, 0, nullptr}},
	component_info{&control_trip5_tag, {SkillShotGate6Control, 0, nullptr}},
	component_info{&control_lite200_tag, {ShootAgainLightControl, 0, nullptr}},
	component_info{&control_sink7_tag, {EscapeChuteSinkControl, 0, nullptr}},
};


component_tag* control::simple_components[142]
{
	&control_lite8_tag,
	&control_lite9_tag,
	&control_lite10_tag,
	&control_bmpr_inc_lights_tag,
	&control_lite171_tag,
	&control_lite170_tag,
	&control_lite169_tag,
	&control_ramp_bmpr_inc_lights_tag,
	&control_lite30_tag,
	&control_lite29_tag,
	&control_lite1_tag,
	&control_lite54_tag,
	&control_lite55_tag,
	&control_lite56_tag,
	&control_lite18_tag,
	&control_lite27_tag,
	&control_lite28_tag,
	&control_lite16_tag,
	&control_lite21_tag,
	&control_lite22_tag,
	&control_lite23_tag,
	&control_lite24_tag,
	&control_lite25_tag,
	&control_lite26_tag,
	&control_lite130_tag,
	&control_lite5_tag,
	&control_lite6_tag,
	&control_lite7_tag,
	&control_worm_hole_lights_tag,
	&control_lite4_tag,
	&control_lite2_tag,
	&control_lite3_tag,
	&control_bsink_arrow_lights_tag,
	&control_l_trek_lights_tag,
	&control_r_trek_lights_tag,
	&control_literoll179_tag,
	&control_literoll180_tag,
	&control_literoll181_tag,
	&control_literoll182_tag,
	&control_literoll183_tag,
	&control_literoll184_tag,
	&control_fuel_bargraph_tag,
	&control_lite20_tag,
	&control_lite19_tag,
	&control_lite61_tag,
	&control_lite58_tag,
	&control_lite11_tag,
	&control_lite12_tag,
	&control_lite13_tag,
	&control_lite70_tag,
	&control_lite71_tag,
	&control_lite72_tag,
	&control_top_circle_tgt_lights_tag,
	&control_lite101_tag,
	&control_lite102_tag,
	&control_lite103_tag,
	&control_ramp_tgt_lights_tag,
	&control_lite104_tag,
	&control_lite105_tag,
	&control_lite106_tag,
	&control_lite107_tag,
	&control_lite108_tag,
	&control_lite109_tag,
	&control_lchute_tgt_lights_tag,
	&control_bpr_solotgt_lights_tag,
	&control_lite110_tag,
	&control_lite62_tag,
	&control_lite67_tag,
	&control_lite68_tag,
	&control_lite69_tag,
	&control_lite131_tag,
	&control_lite132_tag,
	&control_lite133_tag,
	&control_skill_shot_lights_tag,
	&control_lite77_tag,
	&control_lite198_tag,
	&control_middle_circle_tag,
	&control_outer_circle_tag,
	&control_soundwave9_tag,
	&control_soundwave10_tag,
	&control_soundwave21_tag,
	&control_soundwave23_tag,
	&control_soundwave24_tag,
	&control_soundwave30_tag,
	&control_soundwave28_tag,
	&control_soundwave50_1_tag,
	&control_soundwave8_tag,
	&control_soundwave40_tag,
	&control_soundwave41_tag,
	&control_soundwave36_1_tag,
	&control_soundwave50_2_tag,
	&control_soundwave35_1_tag,
	&control_soundwave36_2_tag,
	&control_soundwave35_2_tag,
	&control_soundwave38_tag,
	&control_soundwave39_tag,
	&control_soundwave44_tag,
	&control_soundwave45_tag,
	&control_soundwave46_tag,
	&control_soundwave47_tag,
	&control_soundwave48_tag,
	&control_soundwave52_tag,
	&control_soundwave14_1_tag,
	&control_soundwave59_tag,
	&control_lite199_tag,
	&control_lite196_tag,
	&control_lite195_tag,
	&control_info_text_box_tag,
	&control_mission_text_box_tag,
	&control_soundwave27_tag,
	&control_lite84_tag,
	&control_lite85_tag,
	&control_soundwave14_2_tag,
	&control_soundwave3_tag,
	&control_soundwave26_tag,
	&control_soundwave49D_tag,
	&control_lite300_tag,
	&control_lite301_tag,
	&control_lite302_tag,
	&control_lite303_tag,
	&control_lite304_tag,
	&control_lite305_tag,
	&control_lite306_tag,
	&control_lite307_tag,
	&control_lite308_tag,
	&control_lite309_tag,
	&control_lite310_tag,
	&control_lite311_tag,
	&control_lite312_tag,
	&control_lite313_tag,
	&control_lite314_tag,
	&control_lite315_tag,
	&control_lite316_tag,
	&control_lite317_tag,
	&control_lite318_tag,
	&control_lite319_tag,
	&control_lite320_tag,
	&control_lite321_tag,
	&control_lite322_tag,
	&control_goal_lights_tag,
	&control_soundwave25_tag,
	&control_soundwave7_tag
};

int control::table_unlimited_balls;
int control::extraball_light_flag;
int control::RankRcArray[9] = {84, 85, 86, 87, 88, 89, 90, 91, 92};
int control::MissionRcArray[17] = {60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76};

void control::make_links(TPinballTable* table)
{
	TableG = table;

	for (int index = 0; index < 88; index++)
	{
		auto compPtr = &score_components[index];
		TPinballComponent* comp = make_component_link(compPtr->Tag);
		if (comp)
		{
			comp->Control = &compPtr->Control;
			for (int scoreId = 0; scoreId < compPtr->Control.ScoreCount; scoreId++)
			{
				comp->put_scoring(scoreId, compPtr->Control.Scores[scoreId]);
			}
		}
	}

	for (int i = 0; i < 142; ++i)
		make_component_link(simple_components[i]);
}


TPinballComponent* control::make_component_link(component_tag* tag)
{
	if (tag->Component)
		return tag->Component;

	auto compList = TableG->ComponentList;
	for (int index = 0; index < compList->Count(); index++)
	{
		auto comp = static_cast<TPinballComponent*>(compList->Get(index));
		if (comp->GroupName)
		{
			if (!strcmp(comp->GroupName, tag->Name))
			{
				tag->Component = comp;
				return comp;
			}
		}
	}

	return nullptr;
}

void control::handler(int code, TPinballComponent* cmp)
{
	component_control* control = cmp->Control;
	int scoreInd = 0;
	if (control)
	{
		if (code == 1019 && control->ScoreCount > 0)
		{
			do
			{
				cmp->put_scoring(scoreInd, control->Scores[scoreInd]);
				++scoreInd;
			}
			while (scoreInd < control->ScoreCount);
		}
		control->ControlFunc(code, cmp);
	}
	MissionControl(code, cmp);
}

void control::pbctrl_bdoor_controller(int key)
{
	int v1; // eax
	int v2; // eax
	bool v3; // zf

	if (!control_lite198_tag.Component->MessageField)
	{
		if (key <= 'M')
		{
			if (key == 'M')
			{
				v2 = pbctrl_state;
				if (pbctrl_state == 4 || pbctrl_state == 61 || pbctrl_state == 81 || pbctrl_state == 101)
					goto LABEL_87;
				v3 = pbctrl_state == 121;
			}
			else
			{
				if (key <= 'D')
				{
					if (key != 'D')
					{
						if (key == ' ')
						{
							if (pbctrl_state == 26)
							{
								pbctrl_state = 27;
								return;
							}
							goto LABEL_77;
						}
						if (key != '1')
						{
							if (key != 'A')
							{
								if (key != 'B')
								{
									if (key == 'C')
									{
										if (!pbctrl_state)
										{
											pbctrl_state = 1;
											return;
										}
										if (pbctrl_state == 11)
										{
											pbctrl_state = 12;
											return;
										}
									}
									goto LABEL_77;
								}
								v1 = pbctrl_state != 0 ? 0 : 81;
								goto LABEL_88;
							}
							v2 = pbctrl_state;
							if (pbctrl_state == 5 || pbctrl_state == 62 || pbctrl_state == 82 || pbctrl_state == 102)
								goto LABEL_87;
							v3 = pbctrl_state == 122;
							goto LABEL_86;
						}
						v1 = pbctrl_state != 0 ? 0 : 61;
					LABEL_88:
						pbctrl_state = v1;
						return;
					}
					if (pbctrl_state != 22 && pbctrl_state != 23)
						goto LABEL_77;
				LABEL_58:
					++pbctrl_state;
					return;
				}
				if (key != 'E')
				{
					switch (key)
					{
					case 'G':
						v1 = pbctrl_state != 0 ? 0 : 101;
						break;
					case 'H':
						v1 = pbctrl_state != 0 ? 0 : 21;
						break;
					case 'I':
						v2 = pbctrl_state;
						if (pbctrl_state == 1 || pbctrl_state == 10)
							goto LABEL_87;
						v3 = pbctrl_state == 21;
						goto LABEL_86;
					default:
						goto LABEL_77;
					}
					goto LABEL_88;
				}
				v2 = pbctrl_state;
				if (pbctrl_state == 3 || pbctrl_state == 24 || pbctrl_state == 28)
					goto LABEL_87;
				v3 = pbctrl_state == 44;
			}
			goto LABEL_86;
		}
		if (key <= 'S')
		{
			if (key == 'S')
			{
				v2 = pbctrl_state;
				if (pbctrl_state == 12 || pbctrl_state == 29)
					goto LABEL_87;
				v3 = pbctrl_state == 45;
			}
			else
			{
				if (key != 'N')
				{
					if (key != 'O')
					{
						if (key != 'Q')
						{
							if (key == 'R')
							{
								if (!pbctrl_state)
								{
									pbctrl_state = 121;
									return;
								}
								if (pbctrl_state == 7)
								{
									pbctrl_state = 8;
									return;
								}
							}
							goto LABEL_77;
						}
						v1 = pbctrl_state != 0 ? 0 : 41;
						goto LABEL_88;
					}
					if (pbctrl_state != 8 && pbctrl_state != 42)
						goto LABEL_77;
					goto LABEL_58;
				}
				v2 = pbctrl_state;
				if (pbctrl_state == 2 || pbctrl_state == 9)
					goto LABEL_87;
				v3 = pbctrl_state == 25;
			}
		LABEL_86:
			if (v3)
			{
			LABEL_87:
				v1 = v2 + 1;
				goto LABEL_88;
			}
		LABEL_77:
			pbctrl_state = 0;
			return;
		}
		switch (key)
		{
		case 'T':
			v2 = pbctrl_state;
			if (pbctrl_state != 30)
			{
				if (pbctrl_state == 27 || pbctrl_state == 6)
					goto LABEL_87;
				v3 = pbctrl_state == 43;
				goto LABEL_86;
			}
			pb::cheat_mode = 1;
			break;
		case 'U':
			if (pbctrl_state == 41)
			{
				pbctrl_state = 42;
				return;
			}
			goto LABEL_77;
		case 'X':
			if (pbctrl_state == 63)
			{
				table_add_extra_ball(2.0);
				goto LABEL_76;
			}
			if (pbctrl_state != 83)
			{
				if (pbctrl_state == 103)
				{
					GravityWellKickoutControl(64, nullptr);
				}
				else
				{
					if (pbctrl_state != 123)
						goto LABEL_77;
					cheat_bump_rank();
				}
			LABEL_76:
				TableG->CheatsUsed = 1;
				goto LABEL_77;
			}
			table_unlimited_balls = 1;
			break;
		default:
			goto LABEL_77;
		}
		TableG->CheatsUsed = 1;
		goto LABEL_77;
	}
}

void control::table_add_extra_ball(float count)
{
	++TableG->ExtraBalls;
	static_cast<TSound*>(control_soundwave28_tag.Component)->Play();
	auto msg = pinball::get_rc_string(9, 0);
	static_cast<TTextBox*>(control_info_text_box_tag.Component)->Display(msg, count);
}

void control::table_set_bonus_hold()
{
	control_lite58_tag.Component->Message(19, 0.0);
	static_cast<TTextBox*>(control_info_text_box_tag.Component)->Display(pinball::get_rc_string(52, 0), 2.0);
}

void control::table_set_bonus()
{
	TableG->ScoreSpecial2Flag = 1;
	control_lite59_tag.Component->Message(9, 60.0);
	static_cast<TTextBox*>(control_info_text_box_tag.Component)->Display(pinball::get_rc_string(4, 0), 2.0);
}

void control::table_set_jackpot()
{
	TableG->ScoreSpecial3Flag = 1;
	control_lite60_tag.Component->Message(9, 60.0);
	static_cast<TTextBox*>(control_info_text_box_tag.Component)->Display(pinball::get_rc_string(15, 0), 2.0);
}

void control::table_set_flag_lights()
{
	control_lite20_tag.Component->Message(9, 60.0);
	control_lite19_tag.Component->Message(9, 60.0);
	control_lite61_tag.Component->Message(9, 60.0);
	static_cast<TTextBox*>(control_info_text_box_tag.Component)->Display(pinball::get_rc_string(51, 0), 2.0);
}

int control::cheat_bump_rank()
{
	return 0;
}

bool control::light_on(component_tag* tag)
{
	auto light = static_cast<TLight*>(tag->Component);
	return light->BmpIndex1 || light->FlasherFlag2 || light->FlasherActive;
}

int control::SpecialAddScore(int score)
{
	int prevFlag1 = TableG->ScoreSpecial3Flag;
	TableG->ScoreSpecial3Flag = 0;
	int prevFlag2 = TableG->ScoreSpecial2Flag;
	TableG->ScoreSpecial2Flag = 0;
	int prevMult = TableG->ScoreMultiplier;
	TableG->ScoreMultiplier = 0;

	int addedScore = TableG->AddScore(score);
	TableG->ScoreSpecial2Flag = prevFlag2;
	TableG->ScoreMultiplier = prevMult;
	TableG->ScoreSpecial3Flag = prevFlag1;
	return addedScore;
}

int control::AddRankProgress(int rank)
{
	char Buffer[64];
	int result = 0;

	control_lite16_tag.Component->Message(19, 0.0);
	TPinballComponent* outerCircle = control_outer_circle_tag.Component;
	for (int index = rank; index; --index)
	{
		outerCircle->Message(41, 2.0);
	}

	int activeCount = outerCircle->Message(37, 0.0);
	int totalCount = outerCircle->Message(38, 0.0);
	if (activeCount == totalCount)
	{
		result = 1;
		outerCircle->Message(16, 5.0);
		TPinballComponent* middleCircle = control_middle_circle_tag.Component;
		control_middle_circle_tag.Component->Message(34, 0.0);
		int midActiveCount = middleCircle->Message(37, 0.0);
		if (midActiveCount < 9)
		{
			middleCircle->Message(41, 5.0);
			auto rankText = pinball::get_rc_string(RankRcArray[midActiveCount], 1);
			sprintf_s(Buffer, pinball::get_rc_string(83, 0), rankText);
			static_cast<TTextBox*>(control_mission_text_box_tag.Component)->Display(Buffer, 8.0);
			static_cast<TSound*>(control_soundwave10_tag.Component)->Play();
		}
	}
	else if (activeCount >= 3 * totalCount / 4)
	{
		control_middle_circle_tag.Component->Message(27, -1.0);
	}
	return result;
}

void control::AdvanceWormHoleDestination(int flag)
{
	int lite198Msg = control_lite198_tag.Component->MessageField;
	if (lite198Msg != 16 && lite198Msg != 22 && lite198Msg != 23)
	{
		int lite4Msg = control_lite4_tag.Component->MessageField;
		if (flag || lite4Msg)
		{
			int val1 = lite4Msg + 1;
			int val2 = val1;
			if (val1 == 4)
			{
				val1 = 1;
				val2 = 1;
			}
			control_bsink_arrow_lights_tag.Component->Message(23, static_cast<float>(val2));
			control_bsink_arrow_lights_tag.Component->Message(11, static_cast<float>(3 - val1));
			if (!light_on(&control_lite4_tag))
			{
				control_worm_hole_lights_tag.Component->Message(19, 0.0);
				control_bsink_arrow_lights_tag.Component->Message(19, 0.0);
			}
		}
	}
}

void control::FlipperRebounderControl1(int code, TPinballComponent* caller)
{
	if (code == 63)
	{
		control_lite84_tag.Component->Message(9, 0.1f);
		auto score = caller->get_scoring(0);
		TableG->AddScore(score);
	}
}

void control::FlipperRebounderControl2(int code, TPinballComponent* caller)
{
	if (code == 63)
	{
		control_lite85_tag.Component->Message(9, 0.1f);
		int score = caller->get_scoring(0);
		TableG->AddScore(score);
	}
}

void control::RebounderControl(int code, TPinballComponent* caller)
{
}

void control::BumperControl(int code, TPinballComponent* caller)
{
	if (code == 63)
	{
		TableG->AddScore(caller->get_scoring(static_cast<TBumper*>(caller)->BmpIndex));
	}
}

void control::LeftKickerControl(int code, TPinballComponent* caller)
{
}

void control::RightKickerControl(int code, TPinballComponent* caller)
{
}

void control::LeftKickerGateControl(int code, TPinballComponent* caller)
{
}

void control::RightKickerGateControl(int code, TPinballComponent* caller)
{
}

void control::DeploymentChuteToEscapeChuteOneWayControl(int code, TPinballComponent* caller)
{
	char Buffer[64];
	if (code == 63)
	{
		int count = control_skill_shot_lights_tag.Component->Message(37, 0.0);
		if (count)
		{
			static_cast<TSound*>(control_soundwave3_tag.Component)->Play();
			int score = TableG->AddScore(caller->get_scoring(count - 1));
			sprintf_s(Buffer, pinball::get_rc_string(21, 0), score);
			static_cast<TTextBox*>(control_info_text_box_tag.Component)->Display(Buffer, 2.0);
			if (!light_on(&control_lite56_tag))
			{
				control_l_trek_lights_tag.Component->Message(34, 0.0);
				control_l_trek_lights_tag.Component->Message(20, 0.0);
				control_r_trek_lights_tag.Component->Message(34, 0.0);
				control_r_trek_lights_tag.Component->Message(20, 0.0);
			}
			control_skill_shot_lights_tag.Component->Message(44, 1.0);
		}
	}
}

void control::DeploymentChuteToTableOneWayControl(int code, TPinballComponent* caller)
{
	if (code == 63)
		control_skill_shot_lights_tag.Component->Message(20, 0.0);
}

void control::DrainBallBlockerControl(int code, TPinballComponent* caller)
{
	int msgCode;
	float msgValue;

	auto block = static_cast<TBlocker*>(caller);
	if (code == 52)
	{
		block->MessageField = 1;
		block->Message(52, static_cast<float>(block->TurnOnMsgValue));
		msgValue = static_cast<float>(block->TurnOnMsgValue);
		msgCode = 9;
	}
	else
	{
		if (code != 60)
			return;
		if (block->MessageField != 1)
		{
			block->MessageField = 0;
			block->Message(51, 0.0);
			return;
		}
		block->MessageField = 2;
		block->Message(59, static_cast<float>(block->TurnOffMsgValue));
		msgValue = static_cast<float>(block->TurnOffMsgValue);
		msgCode = 7;
	}
	control_lite1_tag.Component->Message(msgCode, msgValue);
}

void control::LaunchRampControl(int code, TPinballComponent* caller)
{
}

void control::LaunchRampHoleControl(int code, TPinballComponent* caller)
{
}

void control::SpaceWarpRolloverControl(int code, TPinballComponent* caller)
{
}

void control::ReentryLanesRolloverControl(int code, TPinballComponent* caller)
{
}

void control::BumperGroupControl(int code, TPinballComponent* caller)
{
	if (code == 61)
	{
		if (static_cast<TBumper*>(caller)->BmpIndex)
		{
			caller->Message(48, 60.0);
			caller->Message(13, 0.0);
		}
	}
}

void control::LaunchLanesRolloverControl(int code, TPinballComponent* caller)
{
}

void control::OutLaneRolloverControl(int code, TPinballComponent* caller)
{
}

void control::ExtraBallLightControl(int code, TPinballComponent* caller)
{
	if (code == 19)
	{
		control_lite17_tag.Component->Message(9, 55.0);
		control_lite18_tag.Component->Message(9, 55.0);
		extraball_light_flag = 1;
	}
	else if (code == 60)
	{
		if (extraball_light_flag)
		{
			control_lite17_tag.Component->Message(7, 5.0);
			control_lite18_tag.Component->Message(7, 5.0);
			extraball_light_flag = 0;
		}
	}
}

void control::ReturnLaneRolloverControl(int code, TPinballComponent* caller)
{
}

void control::BonusLaneRolloverControl(int code, TPinballComponent* caller)
{
	char Buffer[64];

	if (code == 63)
	{
		if (light_on(&control_lite16_tag))
		{
			int addedScore = SpecialAddScore(TableG->ScoreSpecial2);
			sprintf_s(Buffer, pinball::get_rc_string(3, 0), addedScore);
			static_cast<TTextBox*>(control_info_text_box_tag.Component)->Display(Buffer, 2.0);
			control_lite16_tag.Component->Message(20, 0.0);
			static_cast<TSound*>(control_soundwave50_1_tag.Component)->Play();
		}
		else
		{
			TableG->AddScore(caller->get_scoring(0));
			static_cast<TSound*>(control_soundwave25_tag.Component)->Play();
			static_cast<TTextBox*>(control_info_text_box_tag.Component)->Display(pinball::get_rc_string(44, 0), 2.0);
		}
		control_fuel_bargraph_tag.Component->Message(45, 11.0);
	}
}

void control::FuelRollover1Control(int code, TPinballComponent* caller)
{
	if (code == 63)
	{
		if (control_fuel_bargraph_tag.Component->Message(37, 0.0) > 1)
		{
			control_literoll179_tag.Component->Message(8, 0.05f);
		}
		else
		{
			control_fuel_bargraph_tag.Component->Message(45, 1.0);
			static_cast<TTextBox*>(control_info_text_box_tag.Component)->Display(pinball::get_rc_string(44, 0), 2.0);
		}
		TableG->AddScore(caller->get_scoring(0));
	}
}

void control::FuelRollover2Control(int code, TPinballComponent* caller)
{
	if (code == 63)
	{
		if (control_fuel_bargraph_tag.Component->Message(37, 0.0) > 3)
		{
			control_literoll180_tag.Component->Message(8, 0.05f);
		}
		else
		{
			control_fuel_bargraph_tag.Component->Message(45, 3.0);
			static_cast<TTextBox*>(control_info_text_box_tag.Component)->Display(pinball::get_rc_string(44, 0), 2.0);
		}
		TableG->AddScore(caller->get_scoring(0));
	}
}

void control::FuelRollover3Control(int code, TPinballComponent* caller)
{
	if (code == 63)
	{
		if (control_fuel_bargraph_tag.Component->Message(37, 0.0) > 5)
		{
			control_literoll181_tag.Component->Message(8, 0.05f);
		}
		else
		{
			control_fuel_bargraph_tag.Component->Message(45, 5.0);
			static_cast<TTextBox*>(control_info_text_box_tag.Component)->Display(pinball::get_rc_string(44, 0), 2.0);
		}
		TableG->AddScore(caller->get_scoring(0));
	}
}

void control::FuelRollover4Control(int code, TPinballComponent* caller)
{
	if (code == 63)
	{
		if (control_fuel_bargraph_tag.Component->Message(37, 0.0) > 7)
		{
			control_literoll182_tag.Component->Message(8, 0.05f);
		}
		else
		{
			control_fuel_bargraph_tag.Component->Message(45, 7.0);
			static_cast<TTextBox*>(control_info_text_box_tag.Component)->Display(pinball::get_rc_string(44, 0), 2.0);
		}
		TableG->AddScore(caller->get_scoring(0));
	}
}

void control::FuelRollover5Control(int code, TPinballComponent* caller)
{
	if (code == 63)
	{
		if (control_fuel_bargraph_tag.Component->Message(37, 0.0) > 9)
		{
			control_literoll183_tag.Component->Message(8, 0.05f);
		}
		else
		{
			control_fuel_bargraph_tag.Component->Message(45, 9.0);
			static_cast<TTextBox*>(control_info_text_box_tag.Component)->Display(pinball::get_rc_string(44, 0), 2.0);
		}
		TableG->AddScore(caller->get_scoring(0));
	}
}

void control::FuelRollover6Control(int code, TPinballComponent* caller)
{
	if (code == 63)
	{
		if (control_fuel_bargraph_tag.Component->Message(37, 0.0) > 11)
		{
			control_literoll184_tag.Component->Message(8, 0.05f);
		}
		else
		{
			control_fuel_bargraph_tag.Component->Message(45, 11.0);
			static_cast<TTextBox*>(control_info_text_box_tag.Component)->Display(pinball::get_rc_string(44, 0), 2.0);
		}
		TableG->AddScore(caller->get_scoring(0));
	}
}

void control::HyperspaceLightGroupControl(int code, TPinballComponent* caller)
{
}

void control::WormHoleControl(int code, TPinballComponent* caller)
{
}

void control::LeftFlipperControl(int code, TPinballComponent* caller)
{
}

void control::RightFlipperControl(int code, TPinballComponent* caller)
{
}

void control::JackpotLightControl(int code, TPinballComponent* caller)
{
}

void control::BonusLightControl(int code, TPinballComponent* caller)
{
	if (code == 60)
		TableG->ScoreSpecial2Flag = 0;
}

void control::BoosterTargetControl(int code, TPinballComponent* caller)
{
	TPinballComponent* sound = nullptr;

	if (code == 63 && !caller->MessageField)
	{
		caller->MessageField = 1;
		if (control_target1_tag.Component->MessageField
			+ control_target2_tag.Component->MessageField
			+ control_target3_tag.Component->MessageField != 3)
		{
			TableG->AddScore(caller->get_scoring(0));
			return;
		}
		if (light_on(&control_lite61_tag))
		{
			if (light_on(&control_lite60_tag))
			{
				if (light_on(&control_lite59_tag))
				{
					if (light_on(&control_lite58_tag))
					{
						TableG->AddScore(caller->get_scoring(1));
					}
					else
					{
						table_set_bonus_hold();
					}
					sound = control_soundwave48_tag.Component;
				}
				else
				{
					table_set_bonus();
					sound = control_soundwave46_tag.Component;
				}
			}
			else
			{
				table_set_jackpot();
				sound = control_soundwave45_tag.Component;
			}
		}
		else
		{
			int msg = control_lite198_tag.Component->MessageField;
			if (msg != 15 && msg != 29)
			{
				table_set_flag_lights();
				sound = control_soundwave47_tag.Component;
			}
		}
		if (sound)
			static_cast<TSound*>(sound)->Play();

		control_target1_tag.Component->MessageField = 0;
		control_target1_tag.Component->Message(50, 0.0);
		control_target2_tag.Component->MessageField = 0;
		control_target2_tag.Component->Message(50, 0.0);
		control_target3_tag.Component->MessageField = 0;
		control_target3_tag.Component->Message(50, 0.0);
		TableG->AddScore(caller->get_scoring(1));
	}
}

void control::MedalLightGroupControl(int code, TPinballComponent* caller)
{
}

void control::MultiplierLightGroupControl(int code, TPinballComponent* caller)
{
}

void control::FuelSpotTargetControl(int code, TPinballComponent* caller)
{
	TPinballComponent* liteComp;

	if (code == 63)
	{
		if (control_target10_tag.Component == caller)
		{
			liteComp = control_lite70_tag.Component;
		}
		else
		{
			liteComp = control_lite71_tag.Component;
			if (control_target11_tag.Component != caller)
				liteComp = control_lite72_tag.Component;
		}
		liteComp->Message(15, 2.0);
		TableG->AddScore(caller->get_scoring(0));
		if (control_top_circle_tgt_lights_tag.Component->Message(37, 0.0) == 3)
		{
			control_top_circle_tgt_lights_tag.Component->Message(16, 2.0);
			control_fuel_bargraph_tag.Component->Message(45, 11.0);
			static_cast<TSound*>(control_soundwave25_tag.Component)->Play();
			static_cast<TTextBox*>(control_info_text_box_tag.Component)->Display(pinball::get_rc_string(44, 0), 2.0);
		}
		else
		{
			static_cast<TSound*>(control_soundwave49D_tag.Component)->Play();
		}
	}
}

void control::MissionSpotTargetControl(int code, TPinballComponent* caller)
{
}

void control::LeftHazardSpotTargetControl(int code, TPinballComponent* caller)
{
}

void control::RightHazardSpotTargetControl(int code, TPinballComponent* caller)
{
}

void control::WormHoleDestinationControl(int code, TPinballComponent* caller)
{
}

void control::BlackHoleKickoutControl(int code, TPinballComponent* caller)
{
	char Buffer[64];

	if (code == 63)
	{
		int addedScore = TableG->AddScore(caller->get_scoring(0));
		sprintf_s(Buffer, pinball::get_rc_string(80, 0), addedScore);
		static_cast<TTextBox*>(control_info_text_box_tag.Component)->Display(Buffer, 2.0);
		caller->Message(55, -1.0);
	}
}

void control::FlagControl(int code, TPinballComponent* caller)
{
	if (code == 62)
	{
		AdvanceWormHoleDestination(0);
	}
	else if (code == 63)
	{
		int score = caller->get_scoring(light_on(&control_lite20_tag));
		TableG->AddScore(score);
	}
}

void control::GravityWellKickoutControl(int code, TPinballComponent* caller)
{
}

void control::SkillShotGate1Control(int code, TPinballComponent* caller)
{
}

void control::SkillShotGate2Control(int code, TPinballComponent* caller)
{
}

void control::SkillShotGate3Control(int code, TPinballComponent* caller)
{
}

void control::SkillShotGate4Control(int code, TPinballComponent* caller)
{
}

void control::SkillShotGate5Control(int code, TPinballComponent* caller)
{
}

void control::SkillShotGate6Control(int code, TPinballComponent* caller)
{
}

void control::ShootAgainLightControl(int code, TPinballComponent* caller)
{
}

void control::EscapeChuteSinkControl(int code, TPinballComponent* caller)
{
	if (code == 63)
		caller->Message(56, static_cast<TSink*>(caller)->TimerTime);
}

void control::MissionControl(int code, TPinballComponent* caller)
{
}

void control::HyperspaceKickOutControl(int code, TPinballComponent* caller)
{
}

void control::PlungerControl(int code, TPinballComponent* caller)
{
	if (code == 1015)
	{
		MissionControl(67, nullptr);
	}
	else if (code == 1016)
	{
		table_unlimited_balls = 0;
		if (!control_middle_circle_tag.Component->Message(37, 0.0))
			control_middle_circle_tag.Component->Message(32, 0.0);
		if (!light_on(&control_lite200_tag))
		{
			control_skill_shot_lights_tag.Component->Message(20, 0.0);
			control_lite67_tag.Component->Message(19, 0.0);
			control_skill_shot_lights_tag.Component->Message(26, 0.25f);
			control_l_trek_lights_tag.Component->Message(20, 0.0);
			control_l_trek_lights_tag.Component->Message(32, 0.2f);
			control_l_trek_lights_tag.Component->Message(26, 0.2f);
			control_r_trek_lights_tag.Component->Message(20, 0.0);
			control_r_trek_lights_tag.Component->Message(32, 0.2f);
			control_r_trek_lights_tag.Component->Message(26, 0.2f);
			TableG->ScoreSpecial1 = 25000;
			MultiplierLightGroupControl(65, control_top_target_lights_tag.Component);
			control_fuel_bargraph_tag.Component->Message(19, 0.0);
			control_lite200_tag.Component->Message(19, 0.0);
			control_gate1_tag.Component->Message(53, 0.0);
			control_gate2_tag.Component->Message(53, 0.0);
		}
		control_lite200_tag.Component->MessageField = 0;
	}
}

void control::MedalTargetControl(int code, TPinballComponent* caller)
{
}

void control::MultiplierTargetControl(int code, TPinballComponent* caller)
{
}

void control::BallDrainControl(int code, TPinballComponent* caller)
{
	char Buffer[64];

	if (code == 60)
	{
		if (control_lite199_tag.Component->MessageField)
		{
			TableG->Message(1022, 0.0);
			if (pb::chk_highscore())
			{
				static_cast<TSound*>(control_soundwave3_tag.Component)->Play();
				TableG->LightGroup->Message(16, 3.0);
				char* v11 = pinball::get_rc_string(177, 0);
				static_cast<TTextBox*>(control_mission_text_box_tag.Component)->Display(v11, -1.0);
			}
		}
		else
		{
			control_plunger_tag.Component->Message(1016, 0.0);
		}
	}
	else if (code == 63)
	{
		if (table_unlimited_balls)
		{
			control_drain_tag.Component->Message(1024, 0.0);
			control_sink3_tag.Component->Message(56, 0.0);
		}
		else
		{
			if (TableG->TiltLockFlag)
			{
				control_lite200_tag.Component->Message(20, 0.0);
				control_lite199_tag.Component->Message(20, 0.0);
			}
			if (light_on(&control_lite200_tag))
			{
				static_cast<TSound*>(control_soundwave27_tag.Component)->Play();
				control_lite200_tag.Component->Message(19, 0.0);
				static_cast<TTextBox*>(control_info_text_box_tag.Component)->Display(
					pinball::get_rc_string(96, 0), -1.0);
				static_cast<TSound*>(control_soundwave59_tag.Component)->Play();
			}
			else if (light_on(&control_lite199_tag))
			{
				static_cast<TSound*>(control_soundwave27_tag.Component)->Play();
				control_lite199_tag.Component->Message(20, 0.0);
				control_lite200_tag.Component->Message(19, 0.0);
				static_cast<TTextBox*>(control_info_text_box_tag.Component)->
					Display(pinball::get_rc_string(95, 0), 2.0);
				static_cast<TSound*>(control_soundwave59_tag.Component)->Play();
				--TableG->UnknownP78;
			}
			else if (TableG->UnknownP75)
			{
				static_cast<TSound*>(control_soundwave27_tag.Component)->Play();
				--TableG->UnknownP75;
			}
			else
			{
				if (!TableG->TiltLockFlag)
				{
					int time = SpecialAddScore(TableG->ScoreSpecial2);
					sprintf_s(Buffer, pinball::get_rc_string(94, 0), time);
					static_cast<TTextBox*>(control_info_text_box_tag.Component)->Display(Buffer, 2.0);
				}
				if (TableG->ExtraBalls)
				{
					TableG->ExtraBalls--;

					char* shootAgainText;
					static_cast<TSound*>(control_soundwave59_tag.Component)->Play();
					switch (TableG->CurrentPlayer)
					{
					case 0:
						shootAgainText = pinball::get_rc_string(97, 0);
						break;
					case 1:
						shootAgainText = pinball::get_rc_string(98, 0);
						break;
					case 2:
						shootAgainText = pinball::get_rc_string(99, 0);
						break;
					default:
					case 3:
						shootAgainText = pinball::get_rc_string(100, 0);
						break;
					}
					static_cast<TTextBox*>(control_info_text_box_tag.Component)->Display(shootAgainText, -1.0);
				}
				else
				{
					TableG->ChangeBallCount(TableG->BallCount - 1);
					if (TableG->CurrentPlayer + 1 != TableG->PlayerCount || TableG->BallCount)
					{
						TableG->Message(1021, 0.0);
						control_lite199_tag.Component->MessageField = 0;
					}
					else
					{
						control_lite199_tag.Component->MessageField = 1;
					}
					static_cast<TSound*>(control_soundwave27_tag.Component)->Play();
				}
				control_bmpr_inc_lights_tag.Component->Message(20, 0.0);
				control_ramp_bmpr_inc_lights_tag.Component->Message(20, 0.0);
				control_lite30_tag.Component->Message(20, 0.0);
				control_lite29_tag.Component->Message(20, 0.0);
				control_lite1_tag.Component->Message(20, 0.0);
				control_lite54_tag.Component->Message(20, 0.0);
				control_lite55_tag.Component->Message(20, 0.0);
				control_lite56_tag.Component->Message(20, 0.0);
				control_lite17_tag.Component->Message(20, 0.0);
				control_lite18_tag.Component->Message(20, 0.0);
				control_lite27_tag.Component->Message(20, 0.0);
				control_lite28_tag.Component->Message(20, 0.0);
				control_lite16_tag.Component->Message(20, 0.0);
				control_lite20_tag.Component->Message(20, 0.0);
				control_hyper_lights_tag.Component->Message(20, 0.0);
				control_lite25_tag.Component->Message(20, 0.0);
				control_lite26_tag.Component->Message(20, 0.0);
				control_lite130_tag.Component->Message(20, 0.0);
				control_lite19_tag.Component->Message(20, 0.0);
				control_worm_hole_lights_tag.Component->Message(20, 0.0);
				control_bsink_arrow_lights_tag.Component->Message(20, 0.0);
				control_l_trek_lights_tag.Component->Message(20, 0.0);
				control_r_trek_lights_tag.Component->Message(20, 0.0);
				control_lite60_tag.Component->Message(20, 0.0);
				control_lite59_tag.Component->Message(20, 0.0);
				control_lite61_tag.Component->Message(20, 0.0);
				control_bumber_target_lights_tag.Component->Message(20, 0.0);
				control_top_target_lights_tag.Component->Message(20, 0.0);
				control_top_circle_tgt_lights_tag.Component->Message(20, 0.0);
				control_ramp_tgt_lights_tag.Component->Message(20, 0.0);
				control_lchute_tgt_lights_tag.Component->Message(20, 0.0);
				control_bpr_solotgt_lights_tag.Component->Message(20, 0.0);
				control_lite110_tag.Component->Message(20, 0.0);
				control_skill_shot_lights_tag.Component->Message(20, 0.0);
				control_lite77_tag.Component->Message(20, 0.0);
				control_lite198_tag.Component->Message(20, 0.0);
				control_lite196_tag.Component->Message(20, 0.0);
				control_lite195_tag.Component->Message(20, 0.0);
				control_fuel_bargraph_tag.Component->Message(20, 0.0);
				control_fuel_bargraph_tag.Component->Message(1024, 0.0);
				GravityWellKickoutControl(1024, nullptr);
				control_lite62_tag.Component->Message(20, 0.0);
				control_lite4_tag.Component->MessageField = 0;
				control_lite101_tag.Component->MessageField = 0;
				control_lite102_tag.Component->MessageField = 0;
				control_lite103_tag.Component->MessageField = 0;
				control_ramp_tgt_lights_tag.Component->MessageField = 0;
				control_outer_circle_tag.Component->Message(34, 0.0);
				control_middle_circle_tag.Component->Message(34, 0.0);
				control_attack_bump_tag.Component->Message(1024, 0.0);
				control_launch_bump_tag.Component->Message(1024, 0.0);
				control_gate1_tag.Component->Message(1024, 0.0);
				control_gate2_tag.Component->Message(1024, 0.0);
				control_block1_tag.Component->Message(1024, 0.0);
				control_target1_tag.Component->Message(1024, 0.0);
				control_target2_tag.Component->Message(1024, 0.0);
				control_target3_tag.Component->Message(1024, 0.0);
				control_target6_tag.Component->Message(1024, 0.0);
				control_target5_tag.Component->Message(1024, 0.0);
				control_target4_tag.Component->Message(1024, 0.0);
				control_target9_tag.Component->Message(1024, 0.0);
				control_target8_tag.Component->Message(1024, 0.0);
				control_target7_tag.Component->Message(1024, 0.0);
				if (control_lite199_tag.Component->MessageField)
					control_lite198_tag.Component->MessageField = 32;
				else
					control_lite198_tag.Component->MessageField = 0;
				MissionControl(66, nullptr);
				TableG->Message(1012, 0.0);
				if (light_on(&control_lite58_tag))
					control_lite58_tag.Component->Message(20, 0.0);
				else
					TableG->ScoreSpecial2 = 25000;
			}
		}
	}
}


void control::table_control_handler(int code)
{
	if (code == 1011)
	{
		table_unlimited_balls = 0;
		control_lite77_tag.Component->Message(7, 0.0);
	}
}


void control::AlienMenaceController(int code, TPinballComponent* caller)
{
	if (code != 11)
	{
		if (code == 66)
		{
			control_attack_bump_tag.Component->Message(11, 0.0);
			TPinballComponent* lTrekLight = control_l_trek_lights_tag.Component;
			control_l_trek_lights_tag.Component->Message(20, 0.0);
			lTrekLight->Message(32, 0.2f);
			lTrekLight->Message(26, 0.2f);
			TPinballComponent* rTrekLight = control_r_trek_lights_tag.Component;
			control_r_trek_lights_tag.Component->Message(20, 0.0);
			rTrekLight->Message(32, 0.2f);
			rTrekLight->Message(26, 0.2f);
			control_lite307_tag.Component->Message(7, 0.0);
		}
		else if (code != 67)
		{
			return;
		}
		static_cast<TTextBox*>(control_mission_text_box_tag.Component)->Display(pinball::get_rc_string(175, 0), -1.0);
		return;
	}
	if (control_bump1_tag.Component == caller)
	{
		if (static_cast<TBumper*>(control_bump1_tag.Component)->BmpIndex)
		{
			control_lite307_tag.Component->Message(20, 0.0);
			control_lite198_tag.Component->MessageField = 20;
			MissionControl(66, nullptr);
		}
	}
}

void control::AlienMenacePartTwoController(int code, TPinballComponent* caller)
{
	char Buffer[64];

	if (code != 63)
	{
		if (code == 66)
		{
			control_lite56_tag.Component->MessageField = 8;
			control_l_trek_lights_tag.Component->Message(34, 0.0);
			control_l_trek_lights_tag.Component->Message(20, 0.0);
			control_r_trek_lights_tag.Component->Message(34, 0.0);
			control_r_trek_lights_tag.Component->Message(20, 0.0);
			control_lite308_tag.Component->Message(7, 0.0);
			control_lite311_tag.Component->Message(7, 0.0);
		}
		else if (code != 67)
		{
			return;
		}
		sprintf_s(Buffer, static_cast<const char*>(pinball::get_rc_string(107, 0)),
		          control_lite56_tag.Component->MessageField);
		static_cast<TTextBox*>(control_mission_text_box_tag.Component)->Display(Buffer, -1.0);
		return;
	}
	if (control_bump1_tag.Component == caller
		|| control_bump2_tag.Component == caller
		|| control_bump3_tag.Component == caller
		|| control_bump4_tag.Component == caller)
	{
		control_lite56_tag.Component->MessageField = control_lite56_tag.Component->MessageField - 1;
		if (control_lite56_tag.Component->MessageField)
		{
			MissionControl(67, caller);
		}
		else
		{
			control_lite308_tag.Component->Message(20, 0.0);
			control_lite311_tag.Component->Message(20, 0.0);
			control_lite198_tag.Component->MessageField = 1;
			MissionControl(66, nullptr);
			static_cast<TTextBox*>(control_mission_text_box_tag.Component)->
				Display(pinball::get_rc_string(130, 0), 4.0);
			int addedScore = SpecialAddScore(750000);
			sprintf_s(Buffer, pinball::get_rc_string(78, 0), addedScore);
			if (!AddRankProgress(7))
			{
				static_cast<TTextBox*>(control_mission_text_box_tag.Component)->Display(Buffer, 8.0);
				static_cast<TSound*>(control_soundwave9_tag.Component)->Play();
			}
		}
	}
}

void control::BlackHoleThreatController(int code, TPinballComponent* caller)
{
	char Buffer[64];

	if (code == 11)
	{
		if (control_bump5_tag.Component == caller)
			MissionControl(67, caller);
	}
	else if (code == 63)
	{
		if (control_kickout3_tag.Component == caller
			&& static_cast<TBumper*>(control_bump5_tag.Component)->BmpIndex)
		{
			if (light_on(&control_lite316_tag))
				control_lite316_tag.Component->Message(20, 0.0);
			if (light_on(&control_lite314_tag))
				control_lite314_tag.Component->Message(20, 0.0);
			control_lite198_tag.Component->MessageField = 1;
			MissionControl(66, nullptr);
			static_cast<TTextBox*>(control_mission_text_box_tag.Component)->
				Display(pinball::get_rc_string(124, 0), 4.0);
			int addedScore = SpecialAddScore(1000000);
			sprintf_s(Buffer, pinball::get_rc_string(78, 0), addedScore);
			if (!AddRankProgress(8))
			{
				static_cast<TTextBox*>(control_mission_text_box_tag.Component)->Display(Buffer, 8.0);
				static_cast<TSound*>(control_soundwave9_tag.Component)->Play();
			}
		}
	}
	else
	{
		if (code == 66)
		{
			control_launch_bump_tag.Component->Message(11, 0.0);
		}
		else if (code != 67)
		{
			return;
		}
		if (static_cast<TBumper*>(control_bump5_tag.Component)->BmpIndex)
		{
			static_cast<TTextBox*>(control_mission_text_box_tag.Component)->Display(
				pinball::get_rc_string(123, 0), -1.0);
			if (light_on(&control_lite316_tag))
				control_lite316_tag.Component->Message(20, 0.0);
			if (!light_on(&control_lite314_tag))
			{
				control_lite314_tag.Component->Message(7, 0.0);
			}
		}
		else
		{
			static_cast<TTextBox*>(control_mission_text_box_tag.Component)->Display(
				pinball::get_rc_string(122, 0), -1.0);
			if (light_on(&control_lite314_tag))
				control_lite314_tag.Component->Message(20, 0.0);
			if (!light_on(&control_lite316_tag))
			{
				control_lite316_tag.Component->Message(7, 0.0);
			}
		}
	}
}

void control::BugHuntController(int code, TPinballComponent* caller)
{
	char Buffer[64];

	if (code != 63)
	{
		if (code == 66)
		{
			control_lite56_tag.Component->MessageField = 15;
			control_target1_tag.Component->MessageField = 0;
			control_target1_tag.Component->Message(50, 0.0);
			control_target2_tag.Component->MessageField = 0;
			control_target2_tag.Component->Message(50, 0.0);
			control_target3_tag.Component->MessageField = 0;
			control_target3_tag.Component->Message(50, 0.0);
			control_target6_tag.Component->MessageField = 0;
			control_target6_tag.Component->Message(50, 0.0);
			control_target5_tag.Component->MessageField = 0;
			control_target5_tag.Component->Message(50, 0.0);
			control_target4_tag.Component->MessageField = 0;
			control_target4_tag.Component->Message(50, 0.0);
			control_target9_tag.Component->MessageField = 0;
			control_target9_tag.Component->Message(50, 0.0);
			control_target8_tag.Component->MessageField = 0;
			control_target8_tag.Component->Message(50, 0.0);
			control_target7_tag.Component->MessageField = 0;
			control_target7_tag.Component->Message(50, 0.0);
			control_top_circle_tgt_lights_tag.Component->Message(20, 0.0);
			control_ramp_tgt_lights_tag.Component->Message(20, 0.0);
			control_lchute_tgt_lights_tag.Component->Message(20, 0.0);
			control_bpr_solotgt_lights_tag.Component->Message(20, 0.0);
			control_lite306_tag.Component->Message(7, 0.0);
			control_lite308_tag.Component->Message(7, 0.0);
			control_lite310_tag.Component->Message(7, 0.0);
			control_lite313_tag.Component->Message(7, 0.0);
			control_lite319_tag.Component->Message(7, 0.0);
		}
		else if (code != 67)
		{
			return;
		}
		sprintf_s(Buffer, pinball::get_rc_string(125, 0), control_lite56_tag.Component->MessageField);
		static_cast<TTextBox*>(control_mission_text_box_tag.Component)->Display(Buffer, -1.0);
		return;
	}
	if (control_target1_tag.Component == caller
		|| control_target2_tag.Component == caller
		|| control_target3_tag.Component == caller
		|| control_target6_tag.Component == caller
		|| control_target5_tag.Component == caller
		|| control_target4_tag.Component == caller
		|| control_target9_tag.Component == caller
		|| control_target8_tag.Component == caller
		|| control_target7_tag.Component == caller
		|| control_target10_tag.Component == caller
		|| control_target11_tag.Component == caller
		|| control_target12_tag.Component == caller
		|| control_target13_tag.Component == caller
		|| control_target14_tag.Component == caller
		|| control_target15_tag.Component == caller
		|| control_target16_tag.Component == caller
		|| control_target17_tag.Component == caller
		|| control_target18_tag.Component == caller
		|| control_target19_tag.Component == caller
		|| control_target20_tag.Component == caller
		|| control_target21_tag.Component == caller
		|| control_target22_tag.Component == caller)
	{
		control_lite56_tag.Component->MessageField = control_lite56_tag.Component->MessageField - 1;
		if (control_lite56_tag.Component->MessageField)
		{
			MissionControl(67, caller);
		}
		else
		{
			control_lite306_tag.Component->Message(20, 0.0);
			control_lite308_tag.Component->Message(20, 0.0);
			control_lite310_tag.Component->Message(20, 0.0);
			control_lite313_tag.Component->Message(20, 0.0);
			control_lite319_tag.Component->Message(20, 0.0);
			control_lite198_tag.Component->MessageField = 1;
			MissionControl(66, nullptr);
			static_cast<TTextBox*>(control_mission_text_box_tag.Component)->
				Display(pinball::get_rc_string(126, 0), 4.0);
			int addedScore = SpecialAddScore(750000);
			sprintf_s(Buffer, pinball::get_rc_string(78, 0), addedScore);
			if (!AddRankProgress(7))
			{
				static_cast<TTextBox*>(control_mission_text_box_tag.Component)->Display(Buffer, 8.0);
				static_cast<TSound*>(control_soundwave9_tag.Component)->Play();
			}
		}
	}
}

void control::CosmicPlagueController(int code, TPinballComponent* caller)
{
	char Buffer[64];

	if (code != 63)
	{
		if (code == 66)
		{
			control_lite56_tag.Component->MessageField = 75;
			control_lite20_tag.Component->Message(19, 0.0);
			control_lite19_tag.Component->Message(19, 0.0);
			control_lite305_tag.Component->Message(7, 0.0);
			control_lite312_tag.Component->Message(7, 0.0);
		}
		else if (code != 67)
		{
			return;
		}
		sprintf_s(Buffer, pinball::get_rc_string(139, 0), control_lite56_tag.Component->MessageField);
		static_cast<TTextBox*>(control_mission_text_box_tag.Component)->Display(Buffer, -1.0);
		return;
	}
	if (control_flag1_tag.Component == caller || control_flag2_tag.Component == caller)
	{
		control_lite56_tag.Component->MessageField = control_lite56_tag.Component->MessageField - 1;
		if (control_lite56_tag.Component->MessageField)
		{
			MissionControl(67, caller);
		}
		else
		{
			control_lite305_tag.Component->Message(20, 0.0);
			control_lite312_tag.Component->Message(20, 0.0);
			control_lite198_tag.Component->MessageField = 21;
			MissionControl(66, nullptr);
			control_lite20_tag.Component->Message(20, 0.0);
			control_lite19_tag.Component->Message(20, 0.0);
		}
	}
}

void control::CosmicPlaguePartTwoController(int code, TPinballComponent* caller)
{
	char Buffer[64];

	if (code != 63)
	{
		if (code == 66)
		{
			control_lite310_tag.Component->Message(7, 0.0);
		}
		else if (code != 67)
		{
			return;
		}
		static_cast<TTextBox*>(control_mission_text_box_tag.Component)->Display(pinball::get_rc_string(140, 0), -1.0);
		return;
	}
	if (control_roll9_tag.Component == caller)
	{
		control_lite310_tag.Component->Message(20, 0.0);
		control_lite198_tag.Component->MessageField = 1;
		MissionControl(66, nullptr);
		static_cast<TTextBox*>(control_mission_text_box_tag.Component)->Display(pinball::get_rc_string(141, 0), 4.0);
		int addedScore = SpecialAddScore(1750000);
		sprintf_s(Buffer, pinball::get_rc_string(78, 0), addedScore);
		if (!AddRankProgress(11))
		{
			static_cast<TTextBox*>(control_mission_text_box_tag.Component)->Display(Buffer, 8.0);
			static_cast<TSound*>(control_soundwave9_tag.Component)->Play();
		}
	}
}

void control::DoomsdayMachineController(int code, TPinballComponent* caller)
{
	char Buffer[64];

	if (code != 63)
	{
		if (code == 66)
		{
			control_lite56_tag.Component->MessageField = 3;
			control_lite301_tag.Component->Message(7, 0.0);
			control_lite320_tag.Component->Message(7, 0.0);
		}
		else if (code != 67)
		{
			return;
		}
		sprintf_s(Buffer, pinball::get_rc_string(137, 0), control_lite56_tag.Component->MessageField);
		static_cast<TTextBox*>(control_mission_text_box_tag.Component)->Display(Buffer, -1.0);
		return;
	}
	if (control_roll4_tag.Component == caller || control_roll8_tag.Component == caller)
	{
		control_lite56_tag.Component->MessageField = control_lite56_tag.Component->MessageField - 1;
		if (control_lite56_tag.Component->MessageField)
		{
			MissionControl(67, caller);
		}
		else
		{
			control_lite301_tag.Component->Message(20, 0.0);
			control_lite320_tag.Component->Message(20, 0.0);
			control_lite198_tag.Component->MessageField = 1;
			MissionControl(66, nullptr);
			static_cast<TTextBox*>(control_mission_text_box_tag.Component)->
				Display(pinball::get_rc_string(138, 0), 4.0);
			int addedScore = SpecialAddScore(1250000);
			sprintf_s(Buffer, pinball::get_rc_string(78, 0), addedScore);
			if (!AddRankProgress(9))
			{
				static_cast<TTextBox*>(control_mission_text_box_tag.Component)->Display(Buffer, 8.0);
				static_cast<TSound*>(control_soundwave9_tag.Component)->Play();
			}
		}
	}
}

void control::GameoverController(int code, TPinballComponent* caller)
{
	char Buffer[128];

	if (code == 66)
	{
		control_goal_lights_tag.Component->Message(20, 0.0);
		pb::mode_change(2);
		control_flip1_tag.Component->Message(1022, 0.0);
		control_flip2_tag.Component->Message(1022, 0.0);
		control_mission_text_box_tag.Component->MessageField = 0;
		return;
	}
	if (code != 67)
		return;

	int missionMsg = control_mission_text_box_tag.Component->MessageField;
	if (missionMsg & 0x100)
	{
		int playerId = missionMsg & 0xF;
		int playerScore = TableG->PlayerScores[playerId].ScoreStruct->Score;
		auto nextPlayerId = playerId + 1;
		if (playerScore >= 0)
		{
			const char* playerNScoreText = nullptr;
			switch (nextPlayerId)
			{
			case 1:
				playerNScoreText = pinball::get_rc_string(180, 0);
				break;
			case 2:
				playerNScoreText = pinball::get_rc_string(181, 0);
				break;
			case 3:
				playerNScoreText = pinball::get_rc_string(182, 0);
				break;
			case 4:
				playerNScoreText = pinball::get_rc_string(183, 0);
				break;
			default:
				break;
			}
			if (playerNScoreText != nullptr)
			{
				sprintf_s(Buffer, playerNScoreText, playerScore);
				static_cast<TTextBox*>(control_mission_text_box_tag.Component)->Display(Buffer, 3.0);
				int msgField = nextPlayerId == TableG->PlayerCount ? 0x200 : nextPlayerId | 0x100;
				control_mission_text_box_tag.Component->MessageField = msgField;
				return;
			}
		}
		control_mission_text_box_tag.Component->MessageField = 0x200;
	}

	if (missionMsg & 0x200)
	{
		int highscoreId = missionMsg & 0xF;
		int highScore = pb::highscore_table[highscoreId].Score;
		auto nextHidhscoreId = highscoreId + 1;
		if (highScore > 0)
		{
			const char* highScoreNText = nullptr;
			switch (nextHidhscoreId)
			{
			case 1:
				highScoreNText = pinball::get_rc_string(184, 0);
				break;
			case 2:
				highScoreNText = pinball::get_rc_string(185, 0);
				break;
			case 3:
				highScoreNText = pinball::get_rc_string(186, 0);
				break;
			case 4:
				highScoreNText = pinball::get_rc_string(187, 0);
				break;
			case 5:
				highScoreNText = pinball::get_rc_string(188, 0);
				break;
			default:
				break;
			}
			if (highScoreNText != nullptr)
			{
				sprintf_s(Buffer, highScoreNText, highScore);
				static_cast<TTextBox*>(control_mission_text_box_tag.Component)->Display(Buffer, 3.0);
				int msgField = nextHidhscoreId == 5 ? 0 : nextHidhscoreId | 0x200;
				control_mission_text_box_tag.Component->MessageField = msgField;
				return;
			}
		}
	}
	
	control_mission_text_box_tag.Component->MessageField = 0x100;
	static_cast<TTextBox*>(control_mission_text_box_tag.Component)->Display(pinball::get_rc_string(172, 0), 10.0);
}

void control::LaunchTrainingController(int code, TPinballComponent* caller)
{
}

void control::MaelstromController(int code, TPinballComponent* caller)
{
}

void control::MaelstromPartEightController(int code, TPinballComponent* caller)
{
}

void control::MaelstromPartFiveController(int code, TPinballComponent* caller)
{
}

void control::MaelstromPartFourController(int code, TPinballComponent* caller)
{
}

void control::MaelstromPartSevenController(int code, TPinballComponent* caller)
{
}

void control::MaelstromPartSixController(int code, TPinballComponent* caller)
{
}

void control::MaelstromPartThreeController(int code, TPinballComponent* caller)
{
}

void control::MaelstromPartTwoController(int code, TPinballComponent* caller)
{
}

void control::PracticeMissionController(int code, TPinballComponent* caller)
{
}

void control::ReconnaissanceController(int code, TPinballComponent* caller)
{
}

void control::ReentryTrainingController(int code, TPinballComponent* caller)
{
}

void control::RescueMissionController(int code, TPinballComponent* caller)
{
}

void control::SatelliteController(int code, TPinballComponent* caller)
{
}

void control::ScienceMissionController(int code, TPinballComponent* caller)
{
}

void control::SecretMissionGreenController(int code, TPinballComponent* caller)
{
}

void control::SecretMissionRedController(int code, TPinballComponent* caller)
{
}

void control::SecretMissionYellowController(int code, TPinballComponent* caller)
{
}

void control::SelectMissionController(int code, TPinballComponent* caller)
{
}

void control::SpaceRadiationController(int code, TPinballComponent* caller)
{
}

void control::StrayCometController(int code, TPinballComponent* caller)
{
}

void control::TimeWarpController(int code, TPinballComponent* caller)
{
}

void control::TimeWarpPartTwoController(int code, TPinballComponent* caller)
{
}

void control::UnselectMissionController(int code, TPinballComponent* caller)
{
}

void control::WaitingDeploymentController(int code, TPinballComponent* caller)
{
}