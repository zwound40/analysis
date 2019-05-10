 Setup(AliReducedAnalysisJpsi2eeMult* processor, TString prod="LHC10h", Int_t runNumber=0);

// #define VZEROCBINS
// #define VZEROONLINEBINS
// #define ADBINS
//  #define VZEROABINS 
// #define VZEROBINS 
//   #define VZEROACBINS 
//  #define VZEROCORRBINS 
 #define SYSTEMATICS 0 
 #define TRKBINS
// #define ACC 
//  #define TRKBINSRAW
//#define TRK08BINS
// #define TRK16BINS
// #define TOTALBINS

 
  

enum MCFilters {
   kJpsiInclusive=0,
   kJpsiNonPrompt,
   kJpsiPrompt,
   kJpsiRadiative,
   kJpsiNonRadiative,
   kJpsiDecayElectron,
   kJpsiDecayElectronPrompt,
   kJpsiDecayElectronNonprompt,
   kJpsiDecayElectronRadiative,
   kJpsiDecayElectronNonRadiative};
 
 
 
 
//_________________________________________________________________
void Setup(AliReducedAnalysisJpsi2eeMult* processor, TString prod /*="LHC10h"*/, Int_t runNumber /*=0*/) {
  //
  // Configure the analysis task
  // Setup histograms, handlers, cuts, etc.
  //
  
  processor->SetRunOverMC(kTRUE);
  
  
  AliReducedTrackCut* mcTruthJpsi = new AliReducedTrackCut("inclusiveJpsi", "Pure MC truth J/psi");
  mcTruthJpsi->SetMCFilterBit(kJpsiInclusive);
  mcTruthJpsi->AddCut(AliReducedVarManager::kRap, -0.9, 0.9);
  mcTruthJpsi->AddCut(AliReducedVarManager::kPt, 0., 6.);

  AliReducedTrackCut* mcTruthJpsiElectron = new AliReducedTrackCut("inclusiveJpsiElectron", "Pure MC truth electron from J/psi");
  mcTruthJpsiElectron->SetMCFilterBit(kJpsiDecayElectron);
  mcTruthJpsiElectron->AddCut(AliReducedVarManager::kEta, -0.9, 0.9);
    #ifndef ACC
  mcTruthJpsiElectron->AddCut(AliReducedVarManager::kPt, 0.8, 100.0);
    #endif
  processor->AddJpsiMotherMCCut(mcTruthJpsi, mcTruthJpsiElectron);
  processor->AddLegCandidateMCcut(mcTruthJpsiElectron);
  
  
  

  
  
  
  AliReducedTrackCut* mcTruthJpsiPrompt = new AliReducedTrackCut("promptJpsi", "Pure MC truth J/psi");
  mcTruthJpsiPrompt->SetMCFilterBit(kJpsiPrompt);
  mcTruthJpsiPrompt->AddCut(AliReducedVarManager::kRap, -0.9, 0.9);
   mcTruthJpsiPrompt->AddCut(AliReducedVarManager::kPt, 0., 6.);
  
  AliReducedTrackCut* mcTruthJpsiPromptElectron = new AliReducedTrackCut("promptJpsiElectron", "Pure MC truth electron from J/psi");
  mcTruthJpsiPromptElectron->SetMCFilterBit(kJpsiDecayElectronPrompt);
  mcTruthJpsiPromptElectron->AddCut(AliReducedVarManager::kEta, -0.9, 0.9);
#ifndef ACC
  mcTruthJpsiPromptElectron->AddCut(AliReducedVarManager::kPt, .8, 100.0);
#endif  

  processor->AddJpsiMotherMCCut(mcTruthJpsiPrompt, mcTruthJpsiPromptElectron);
  processor->AddLegCandidateMCcut(mcTruthJpsiPromptElectron);
  
  AliReducedTrackCut* mcTruthJpsiNonprompt = new AliReducedTrackCut("nonpromptJpsi", "Pure MC truth J/psi");
  mcTruthJpsiNonprompt->SetMCFilterBit(kJpsiNonPrompt);
  mcTruthJpsiNonprompt->AddCut(AliReducedVarManager::kRap, -0.9, 0.9);
  mcTruthJpsiNonprompt->AddCut(AliReducedVarManager::kPt, 0., 6.);
  
  AliReducedTrackCut* mcTruthJpsiNonpromptElectron = new AliReducedTrackCut("nonpromptJpsiElectron", "Pure MC truth electron from J/psi");
  mcTruthJpsiNonpromptElectron->SetMCFilterBit(kJpsiDecayElectronNonprompt);
  mcTruthJpsiNonpromptElectron->AddCut(AliReducedVarManager::kEta, -0.9, 0.9);
#ifndef ACC
  mcTruthJpsiNonpromptElectron->AddCut(AliReducedVarManager::kPt, .8, 100.0);
#endif 
  
  processor->AddJpsiMotherMCCut(mcTruthJpsiNonprompt, mcTruthJpsiNonpromptElectron);
  processor->AddLegCandidateMCcut(mcTruthJpsiNonpromptElectron);
  
  
  
  /*  
  
  
  
  AliReducedTrackCut* radiativeJpsi = new AliReducedTrackCut("radiativeJpsi", "Pure MC truth J/psi");
  radiativeJpsi->SetMCFilterBit(kJpsiRadiative);
  radiativeJpsi->AddCut(AliReducedVarManager::kRap, -0.8, 0.8);
 // radiativeJpsi->AddCut(AliReducedVarManager::kPt, 0., 6.);
  
  AliReducedTrackCut* radiativeJpsiElectron = new AliReducedTrackCut("inclusiveJpsiElectron", "Pure MC truth electron from J/psi");
  radiativeJpsiElectron->SetMCFilterBit(kJpsiDecayElectron);
  radiativeJpsiElectron->AddCut(AliReducedVarManager::kEta, -0.8, 0.8);
  radiativeJpsiElectron->AddCut(AliReducedVarManager::kPt, 1.0, 100.0);
  
  processor->AddJpsiMotherMCCut(radiativeJpsi, radiativeJpsiElectron);
  processor->AddLegCandidateMCcut(radiativeJpsiElectron);
  */
  
  
  
  
  
  
  Int_t prefilterType = 0;
  
//    processor->SetRunPairing(0);
   processor->SetRunEventMixing(0);

  
//   processor->SetRunTrackRotation(true);
  
//    processor->SetNRotations(100);
//   
  TFile* trkEtaFile = TFile::Open("/lustre/nyx/alice/users/sweber/TREES/HM/profilesMC_inelgt0.root");
//   TFile* trkEtaFile = TFile::Open("/lustre/nyx/alice/users/sweber/TREES/HM/profilesMC_all.root");

  AliReducedVarManager::SetMultiplicityProfile( (TH2*) trkEtaFile->Get("RunNo_Vtx_Tracklets10_prof") , AliReducedVarManager::kSPDntracklets );
//  AliReducedVarManager::SetMultiplicityProfile( (TH2*) trkEtaFile->Get("RunNo_Vtx_Tracklets08_prof") , AliReducedVarManager::kSPDntracklets08 );
 // AliReducedVarManager::SetMultiplicityProfile( (TH2*) trkEtaFile->Get("RunNo_Vtx_Tracklets05_prof") , AliReducedVarManager::kSPDntracklets05 );
 // AliReducedVarManager::SetMultiplicityProfile( (TH2*) trkEtaFile->Get("RunNo_Vtx_Tracklets16_prof") , AliReducedVarManager::kSPDntracklets16 );
 AliReducedVarManager::SetMultiplicityProfile( (TH2*) trkEtaFile->Get("RunNo_Vtx_VZEROM_prof") , AliReducedVarManager::kVZEROTotalMult);
//  AliReducedVarManager::SetMultiplicityProfile( (TH2*) trkEtaFile->Get("RunNo_Vtx_VZEROA_prof") , AliReducedVarManager::kVZEROATotalMult);
//  AliReducedVarManager::SetMultiplicityProfile( (TH2*) trkEtaFile->Get("RunNo_Vtx_VZEROC_prof") , AliReducedVarManager::kVZEROCTotalMult);
//   for( int ieta = 0; ieta < 32; ++ ieta){
//     AliReducedVarManager::SetMultiplicityProfile( (TH2*) trkEtaFile->Get( Form("RunNo_Vtx_TrackletsEta%d_prof", ieta) ) , AliReducedVarManager::kSPDntrackletsEtaBin + ieta   );
//   }
  trkEtaFile->Close();
  
 /* 
  TFile* alphaTrkFile = TFile::Open("/lustre/nyx/alice/users/sweber/TREES/HM/alpha_nchVsNtrk.root");
  cout << "PROFILE " << alphaTrkFile->Get("hAlpha") << endl;
  AliReducedVarManager::SetAlphaProfile( (TH1*) alphaTrkFile->Get("hAlpha") ,
                                         AliReducedVarManager::kSPDntracklets,
                                         AliReducedVarManager::kVertexCorr,
                                         AliReducedVarManager::kMaximumMultiplicity,
                                         AliReducedVarManager::kPoissonSmearing
                                       );
  alphaTrkFile->Close();
  
  TFile* alphaV0File = TFile::Open("/lustre/nyx/alice/users/sweber/TREES/HM/alpha_v0VsNv0.root");
  AliReducedVarManager::SetAlphaProfile( (TH1*) alphaV0File->Get("hAlpha") ,
                                         AliReducedVarManager::kVZEROTotalMult,
                                         -1,-1, -1
                                       );
  alphaV0File->Close();
  */
  
  
 /* 
  TFile* trkVsV0File = TFile::Open("/lustre/nyx/alice/users/sweber/TREES/HM/trackletsVsV0.root");
  AliReducedVarManager::SetTrackletVsV0Profile( (TH2*)  trkVsV0File->Get("V0A_V0C_SPD")  );
  trkVsV0File->Close();
  */
  
// run numbers
  {

  TString runNumbers;


  AliReducedVarManager::AddPeriod(252235  );
  //16d
  runNumbers += "252235;252248;252271;252310;252317;252319;252322;252325;252330;";
  
  AliReducedVarManager::AddPeriod( 253437 );
  //16e
  runNumbers += "253437;253478;253481;253482;253488;253517;253529;253530;253563;253589;253591;";
   
  AliReducedVarManager::AddPeriod(254128  );
  // 16g
  runNumbers += "254128;254147;254148;254149;254174;254175;254178;254193;254199;254204;254205;254293;254302;254303;254304;254330;254331;254332;";
 
  
  AliReducedVarManager::AddPeriod(254418  );
  //16h --
  runNumbers += "254418;254419;254422;";
  
  
  AliReducedVarManager::AddPeriod(254604  );
  
  //16h ++
  runNumbers += "254604;254606;254608;254629;254630;254632;254640;254644;254646;254648;254649;254651;254652;254653;254654;255079;255082;255085;";
  runNumbers += "255086;255091;255111;255154;255159;255162;255167;255171;255173;255174;255176;255177;255240;255242;255247;255248;255249;255251;255252;";
  runNumbers += "255255;255256;255275;255276;255280;255283;255350;255351;255352;255398;255402;255407;255415;255418;255419;255420;255421;255440;255442;255447;";
  runNumbers += "255463;255465;255466;255467;";
  
  
  AliReducedVarManager::AddPeriod( 255539 );
  // 16i
  runNumbers += "255539;255540;255541;255542;255543;255577;255582;255583;255591;255614;255615;255616;255617;255618;";
  
  AliReducedVarManager::AddPeriod( 256204 );
  // 16j
  runNumbers += "256204;256207;256210;256212;256213;256215;256219;256222;256223;256227;256228;256231;256281;256282;256283;256284;256287;256289;256290;256292;";
  runNumbers += "256295;256297;256298;256299;256302;256307;256309;256311;256356;256357;256361;256362;256363;256364;256365;256366;256368;256371;256372;256373;";
  runNumbers += "256415;256417;256418;256420;";

   /*
   // 16k (old pass1 list)
  runNumbers += "256504;256506;256510;256512;256514;256552;256554;256556;256557;256560;256561;256562;256564;256565;256567;256589;256591;256592;256619;256620;";
  runNumbers += "256658;256676;256677;256681;256684;256691;256692;256694;256695;256697;256941;256942;256944;257011;257012;257021;257026;257028;257077;257080;";
  runNumbers += "257082;257083;257084;257086;257092;257095;257100;257136;257137;257139;257140;257141;257142;257144;257145;257204;257206;257209;257224;";
  runNumbers += "257260;257318;257320;257322;257330;257358;257364;257433;257457;257468;257474;257487;257488;257490;257491;257492;257530;257531;257537;257539;";
  runNumbers += "257540;257541;257560;257561;257562;257566;257587;257588;257590;257592;257594;257595;257601;257604;257605;257606;257630;257632;257635;257636;";
  runNumbers += "257642;257644;257682;257684;257685;257687;257688;257689;257691;257692;257694;257697;257724;257725;257727;257733;257734;257735;257737;257754;";
  runNumbers += "257757;257765;257773;257797;257798;257799;257800;257803;257804;257850;257851;257853;257855;257892;257893;257936;257937;257939;257957;257958;";
  runNumbers += "257963;257979;257986;257989;257992;258003;258008;258012;258014;258017;258019;258039;258041;258042;258045;258048;258049;258053;258059;";
  runNumbers += "258060;258062;258063;258107;258108;258109;258113;258114;258117;258178;258197;258198;258202;258203;258204;258256;258257;258258;258270;258271;";
  runNumbers += "258273;258274;258278;258299;258301;258302;258303;258306;258307;258332;258336;258359;258387;258391;258393;258426;258452;258454;258456;258477;";
  runNumbers += "258499;258537;";
  */


  // 16k (new pass2 list)
 
// excluded because lower number of tracklets: 257138;257960



  AliReducedVarManager::AddPeriod( 256941 );


  runNumbers += "256941;256942;256944;257011;257012;257021;257026;257028;257077;257080;257082;257083;257084;257086;257092;257095;257100;257136;257137;";
  runNumbers += "257139;257140;257141;257142;257144;257145;257204;257206;257209;257224;257260;257318;257320;257322;257330;257358;257364;257433;257457;257468;";
  runNumbers += "257474;257487;257488;257490;257491;257492;257530;257531;257537;257539;257540;257541;257560;257561;257562;257566;257587;257588;257590;257592;";
  runNumbers += "257594;257595;257601;257604;257605;257606;257630;257632;257635;257636;257642;257644;257682;257684;257685;257687;257688;257689;257691;257692;";
  runNumbers += "257694;257697;257724;257725;257727;257733;257734;257735;257737;257754;257757;257765;257773;257797;257798;257799;257800;257803;257804;257850;";
  runNumbers += "257851;257853;257855;257893;257936;257937;257939;257957;257958;257963;257979;257986;257989;257992;258003;258008;258012;258014;258017;";
  runNumbers += "258019;258039;258041;258042;258045;258048;258049;258053;258059;258060;258062;258063;258107;258108;258109;258113;258114;258117;258178;258197;";
  runNumbers += "258198;258202;258203;258204;258256;258257;258258;258270;258271;258273;258274;258278;258299;258301;258302;258303;258306;258307;258332;258336;";
  runNumbers += "258359;258387;258391;258393;258426;258452;258454;258456;258477;258499;258537;";

/*  
  // 16l (old pass1 run list)
  runNumbers += "258919;258923;258962;258964;259088;259090;259091;259096;259099;259117;259118;259162;259164;259204;259257;259261;259263;259264;259269;259270;";
  runNumbers += "259271;259272;259273;259274;259302;259303;259305;259307;259334;259336;259339;259340;259341;259342;259378;259382;259388;259389;259394;259395;";
  runNumbers += "259396;259473;259477;259649;259650;259668;259697;259700;259703;259704;259705;259711;259713;259747;259748;259750;259751;259752;259756;259781;";
  runNumbers += "259788;259789;259822;259841;259842;259860;259866;259867;259868;259888;";
  
*/


  AliReducedVarManager::AddPeriod( 258962 );
  // 16l (new pass2 run list)
  runNumbers += "258962;258964;259088;259090;259091;259096;259099;259117;259118;259162;259164;259204;259257;259261;259263;259264;259269;259270;259271;259272;";
  runNumbers += "259273;259274;259302;259303;259305;259307;259334;259336;259339;259340;259341;259342;259378;259382;259388;259389;259394;259395;259396;259473;";
  runNumbers += "259477;259747;259748;259750;259751;259752;259756;259781;259788;259789;259822;259841;259842;259860;259866;259867;259868;259888;";




  AliReducedVarManager::AddPeriod( 262424 );
  // 16o
  runNumbers += "262424;262425;262426;262428;262705;262706;262708;262713;262717;262719;262723;262725;262727;262760;262768;262776;262777;262778;262841;262842;";
  runNumbers += "262844;262847;262849;262853;262855;262858;263487;263490;263496;263497;263529;263647;263652;263653;263654;263657;263662;263663;";
  runNumbers += "263682;263689;263690;263691;263737;263738;263739;263741;263743;263744;263784;263785;263786;263787;263790;263792;263793;263803;263810;263861;";
  runNumbers += "263863;263866;263905;263916;263917;263920;263923;263977;263978;263981;263984;263985;264033;264035;";
  
  
  AliReducedVarManager::AddPeriod(264076  );
  // 16p
  runNumbers += "264076;264078;264082;264085;264086;264109;264110;264129;264137;264138;264139;264164;264168;264188;264190;264194;264197;264198;264232;264233;";
  runNumbers += "264235;264238;264259;264260;264261;264262;264264;264265;264266;264267;264273;264277;264279;264281;264305;264306;264312;264336;264341;264345;";
  runNumbers += "264346;264347;";
  
 
  // 17g
//  runNumbers += "270882;270883;270931;270934;270935;270937;270938;270940;271005;271006;271008;271009;271289;271369;271373;271377;271378;271379;271381;271382;";
//  runNumbers += "271383;271384;271419;271444;271448;271449;271451;271743;271768;271774;271777;";


  AliReducedVarManager::AddPeriod( 271868 );
  // 17h
  runNumbers += "271868;271870;271871;271873;271874;271880;271881;271886;272018;272020;272036;272038;272039;272040;272041;272042;272076;272100;272101;272123;";
  runNumbers += "272151;272152;272153;272154;272155;272156;272194;272335;272340;272359;272360;272388;272389;272394;272395;272399;272400;272411;272413;272461;";
  runNumbers += "272462;272463;272466;272468;272521;272574;272575;272577;272585;272607;272608;272610;272620;272690;272691;272692;272712;272746;272747;272749;";
  runNumbers += "272760;272763;272764;272782;272783;272784;272828;272829;272833;272834;272836;272870;272871;272873;272880;272903;272905;272932;272933;272934;";
  runNumbers += "272935;272939;272947;272949;272976;272983;272985;273009;273010;273077;273099;273100;273103;";


  AliReducedVarManager::AddPeriod( 273591 );
  // 17i
  runNumbers += "273591;273592;273593;273653;273654;273687;273689;273690;273695;273709;273711;273719;273824;273825;273885;273886;273887;273889;273918;273942;";
  runNumbers += "273943;273946;273985;273986;274058;274064;274092;274094;274125;274147;274148;274174;274212;274232;274258;274259;274263;274264;274266;274268;";
  runNumbers += "274269;274270;274271;274276;274278;274280;274281;274283;274329;274351;274352;274360;274363;274364;274385;274386;274387;274388;274389;274390;";
  runNumbers += "274442;";


  AliReducedVarManager::AddPeriod( 274593 );
  // 17j
  runNumbers += "274593;274594;274595;274596;274601;274653;274657;274667;274669;274671;";


  AliReducedVarManager::AddPeriod( 274690 );
  // 17k
  runNumbers += "274690;274708;274801;274802;274803;274806;274807;274811;274815;274817;274821;274822;274877;274878;274882;274886;274978;274979;275067;275068;";
  runNumbers += "275073;275075;275076;275150;275151;275173;275174;275177;275180;275184;275188;275283;275314;275322;275324;";
  runNumbers += "275326;275328;275332;275333;275360;275361;275369;275372;275394;275395;275401;275404;275406;275443;275448;275452;275453;275456;275457;275459;";
  runNumbers += "275467;275471;275472;275515;275558;275559;275612;275617;275621;275622;275623;275624;275647;275648;275650;275657;275661;275664;275847;275924;";
  runNumbers += "275925;276012;276013;276017;276019;276020;276040;276041;276045;276097;276098;276099;276102;276104;276135;276140;276145;276166;276169;276170;";
  runNumbers += "276177;276178;276205;276230;276257;276259;276290;276291;276292;276294;276297;276302;276307;276312;276348;276351;276435;276437;276438;276439;";
  runNumbers += "276462;276506;276507;276508;";


  AliReducedVarManager::AddPeriod( 276551 );
  // 17l
  runNumbers += "276551;276552;276556;276557;276608;276644;276670;276671;276672;276674;276675;276762;276916;276917;276920;276967;276969;276970;276971;";
  runNumbers += "276972;277015;277016;277017;277037;277073;277076;277079;277082;277087;277091;277117;277121;277155;277180;277182;277183;277184;277188;";
  runNumbers += "277189;277193;277194;277196;277197;277256;277257;277262;277293;277310;277312;277314;277360;277383;277384;277385;277386;277389;277416;277417;";
  runNumbers += "277418;277472;277473;277476;277477;277478;277479;277530;277531;277534;277536;277537;277574;277575;277576;277577;277721;277722;277723;277725;";
  runNumbers += "277745;277746;277747;277749;277794;277795;277799;277800;277801;277802;277805;277834;277836;277841;277842;277845;277847;277848;277870;277876;";
  runNumbers += "277897;277898;277899;277900;277901;277903;277904;277907;277930;277952;277987;277989;277991;277996;278121;278122;278123;278126;278127;278158;";
  runNumbers += "278163;278164;278166;278167;278189;278191;278215;278216;";


  AliReducedVarManager::AddPeriod(278914  );
  // 17m
  runNumbers += "278914;278915;278936;278939;278941;278959;278960;278963;278964;278999;279000;279005;279007;279008;279035;279036;279041;279043;279044;279068;";
  runNumbers += "279069;279073;279074;279075;279106;279107;279117;279118;279122;279123;279130;279155;279157;279199;279201;279207;279208;279232;279234;279235;";
  runNumbers += "279238;279242;279264;279265;279267;279268;279270;279273;279274;279309;279310;279312;279342;279344;279348;279349;279354;279355;279391;279410;";
  runNumbers += "279435;279439;279441;279483;279487;279488;279491;279550;279559;279630;279632;279641;279642;279676;279677;279679;279682;279683;279684;279687;";
  runNumbers += "279688;279689;279715;279718;279719;279747;279749;279773;279826;279827;279830;279853;279854;279879;279880;280051;280052;280066;280107;";
  runNumbers += "280108;280111;280114;280118;280126;280131;280134;280135;280140;";


  AliReducedVarManager::AddPeriod( 280282 );
  // 17o
  runNumbers += "280282;280283;280284;280285;280286;280290;280310;280312;280348;280349;280350;280351;280374;280375;280403;280406;280412;280413;280415;";
  runNumbers += "280419;280443;280445;280446;280447;280448;280490;280499;280518;280519;280546;280547;280550;280551;280574;280575;280576;280581;280583;280613;";
  runNumbers += "280634;280636;280637;280639;280645;280647;280671;280679;280681;280705;280706;280729;280753;280754;280755;280756;280757;280761;280762;280763;";
  runNumbers += "280764;280765;280766;280767;280768;280786;280787;280792;280793;280842;280844;280845;280847;280848;280849;280854;280856;280880;280881;280890;";
  runNumbers += "280897;280936;280940;280943;280947;280990;280994;280996;280997;280998;280999;281032;281033;281035;281036;281060;281061;281062;281080;281081;";
  runNumbers += "281179;281180;281181;281189;281190;281191;281212;281213;281240;281241;281242;281243;281244;281271;281273;281275;281277;281301;281321;281415;";
  runNumbers += "281441;281443;281444;281446;281449;281450;281475;281477;281509;281511;281557;281562;281563;281568;281569;281574;281583;281592;281633;281892;";
  runNumbers += "281893;281894;281895;281915;281916;281918;281920;281928;281931;281932;281939;281940;281953;281956;281961;";


  AliReducedVarManager::AddPeriod(282528  );
  // 17r
  runNumbers += "282528;282544;282545;282546;282573;282575;282579;282580;282606;282607;282608;282609;282618;282620;282622;282629;282651;282653;282666;282667;";
  runNumbers += "282668;282670;282671;282673;282676;282677;282700;282702;282703;282704;";


  AliReducedVarManager::AddPeriod( 285009 );
  // 18b
  runNumbers += "285009;";
//285011;285012;285013;285014;285015;285064;285065;285066;285106;285108;285125;285127;285165;285200;285202;285203;";
  runNumbers += "285222;285224;285327;285328;285347;285364;285365;285396;";



  AliReducedVarManager::AddPeriod( 285978 );
  // 18d
  runNumbers += "285978;285979;285980;286014;286025;286064;286124;286127;286129;286130;286159;286198;286199;286201;286202;286203;286229;";
  runNumbers += "286230;286231;286254;286255;286257;286258;286261;286263;286282;286284;286287;286288;286289;286308;286309;286310;286311;286312;286314;";
  runNumbers += "286336;286337;286340;286341;286345;286348;286349;286350;";


  AliReducedVarManager::AddPeriod( 286380 );
  // 18e
  runNumbers += "286380;286426;286427;286428;286454;286455;286482;286501;286502;286508;286509;286511;286566;286567;286568;286569;286591;286592;286594;286633;";
  runNumbers += "286653;286661;286695;286731;286799;286801;286805;286809;286810;286846;286848;286850;286852;286874;286876;286877;286907;286908;286910;286911;";
  runNumbers += "286930;286931;286932;286933;286936;286937;";


  AliReducedVarManager::AddPeriod(287000  );
  // 18f
  runNumbers += "287000;287021;287063;287066;287071;287072;287077;287137;287155;287185;287201;287202;287203;287204;287208;287209;287248;287249;287250;";
  runNumbers += "287251;287254;287283;287323;287324;287325;287343;287344;287346;287347;287349;287353;287355;287356;287360;287380;287381;287385;287387;287388;";
  runNumbers += "287389;287413;287451;287480;287481;287484;287486;287513;287516;287517;287518;287520;287521;287524;287573;287575;287576;287578;287654;287656;";
  runNumbers += "287657;287658;";


  AliReducedVarManager::AddPeriod( 288619 );
  // 18g
  runNumbers += "288619;288640;288642;288644;288650;288687;288689;288690;288743;288748;288750;";


  AliReducedVarManager::AddPeriod(288806  );
  // 18h
  runNumbers += "288806;";


  AliReducedVarManager::AddPeriod(288861  );
  // 18i
  runNumbers += "288861;288862;288863;288864;288868;288902;288903;288908;288909;";


  AliReducedVarManager::AddPeriod( 288943 );
  // 18j
  runNumbers += "288943;";


  AliReducedVarManager::AddPeriod(289165  );
  // 18k
  runNumbers += "289165;289166;289167;289169;289172;289175;289176;289177;289198;289199;289200;289201;";


  AliReducedVarManager::AddPeriod(289240  );
  // 18l
  runNumbers += "289240;289241;289242;289243;289247;289249;289253;289254;289275;289276;289277;289278;289280;289281;289300;289303;289306;289308;289309;289353;";
  runNumbers += "289354;289355;289356;289365;289366;289367;289368;289369;289370;289373;289374;289426;289444;289462;289463;289465;289466;289468;289494;";
  runNumbers += "289521;289547;289721;289723;289724;289729;289731;289732;289757;289775;289808;289811;289814;289815;289816;289817;289818;289830;289849;289852;";
  runNumbers += "289854;289855;289856;289857;289879;289880;289884;289928;289931;289935;289940;289941;289943;289965;289966;289971;";


  AliReducedVarManager::AddPeriod(290323  );
  // 18m
  runNumbers += "290323;290324;290327;290350;290374;290375;290376;290399;290401;290404;290411;290412;290423;290425;290426;290427;290428;290456;290458;290459;";
  runNumbers += "290467;290469;290499;290500;290501;290549;290550;290553;290588;290590;290627;290632;";
  runNumbers += "290645;290658;290660;290665;290687;290689;290692;290696;290699;290721;290764;290766;290769;290774;290776;290787;290790;290841;290843;290846;";
  runNumbers += "290848;290860;290862;290886;290887;290888;290892;290894;290895;290932;290935;290941;290943;290944;290948;290974;290975;290976;290979;";
  runNumbers += "290980;291002;291003;291004;291005;291006;291035;291037;291041;291065;291066;291069;291093;291100;291101;291110;291111;291116;291143;291188;";
  runNumbers += "291209;291240;291257;291263;291265;291266;291282;291283;291284;291285;291286;291360;291361;291362;291363;291375;291377;291397;291399;";
  runNumbers += "291400;291402;291416;291417;291419;291420;291424;291446;291447;291451;291453;291456;291457;291481;291482;291484;291485;291590;291614;291615;";
  runNumbers += "291618;291622;291624;291626;291690;291692;291694;291697;291698;291702;291706;291729;291755;291756;291760;291762;291766;";
  runNumbers += "291768;291769;291795;291796;291803;291942;291944;291945;291946;291948;291953;291976;291977;291982;292012;292040;292060;292061;292062;";
  runNumbers += "292067;292075;292077;292080;292081;292106;292107;292108;292109;292114;292115;292140;292160;292161;292162;292163;292164;292166;292167;292168;";
  runNumbers += "292192;292218;292240;292241;292242;292265;292269;292270;292273;292274;292298;292397;292398;292405;292406;292428;292429;292430;292432;292434;";
  runNumbers += "292456;292457;292460;292461;292495;292496;292497;292500;292521;292523;292524;292526;292553;292554;292557;292559;292560;292563;292584;292586;";
  runNumbers += "292693;292695;292696;292698;292701;292704;292737;292739;292744;292747;292748;292750;292752;292754;292758;292803;292804;292809;292810;292811;";
  runNumbers += "292831;292832;292834;292836;292839;";


  AliReducedVarManager::AddPeriod(293357  );
  // 18n
  runNumbers += "293357;293359;";


  AliReducedVarManager::AddPeriod( 293475 );
  // 18o
  runNumbers += "293475;293570;293571;293573;293578;293579;293582;293583;293587;293588;293689;293690;293691;293692;293695;293696;293698;293740;293741;";
  runNumbers += "293770;293773;293774;293776;293799;293802;293805;293806;293807;293809;293829;293831;293856;293886;293891;293893;293896;293898;";


  AliReducedVarManager::AddPeriod( 294009 );
  // 18p
  runNumbers += "294009;294010;294011;294012;294013;294156;294199;294200;294201;294205;294208;294210;294212;294241;294242;294307;";
  runNumbers += "294308;294310;294524;294525;294526;294527;294529;294530;294531;294556;294558;294562;294563;294586;294587;294588;294590;294591;294593;";
  runNumbers += "294632;294633;294634;294636;294653;294703;294710;294715;294716;294718;294721;294722;294741;294742;294743;294744;294745;294746;294747;294749;";
  runNumbers += "294769;294772;294774;294775;294805;294809;294813;294816;294817;294818;294852;294875;294877;294880;294883;294884;294916;294925;";



  AliReducedVarManager::SetRunNumbers( runNumbers );


 
  AliReducedVarManager::SetRunNumbers( runNumbers );
  
  
  /*
  Int_t period;
  
  if(       runNumber < 253437 ) period = 0;
  else if ( runNumber < 254128 ) period = 1;
  else if ( runNumber < 254604 ) period = 2;
  else if ( runNumber < 255539 ) period = 3;
  else if ( runNumber < 256204 ) period = 4;
  else if ( runNumber < 256504 ) period = 5;
  else if ( runNumber < 257850 ) period = 6;
  else if ( runNumber < 258919 ) period = 7;
  else if ( runNumber < 262424 ) period = 8;
  else if ( runNumber < 264076 ) period = 9;
  else                           period = 10;
  
  
  
  AliReducedVarManager::SetPeriod( period );
 */ 
  
}
   
  // Set event cuts
  
  
  
  AliReducedEventCut* evCut1 = new AliReducedEventCut("EventCuts","Event cuts");
//  evCut1->AddCut(AliReducedVarManager::kVtxZmc, -10.0, 10.0);
  evCut1->AddCut(AliReducedVarManager::kVtxZ, -10.0, 10.0);
  evCut1->AddCut(AliReducedVarManager::kIsPhysicsSelection, 0.1, 2.);   // request physics selection
  
  
  AliReducedEventCut* evCut2 = new AliReducedVarCut("EventCuts2","Event cuts 2");
//   evCut2->AddCut(AliReducedVarManager::kNMCtruthJpsiLegs, 1. , 1.);
  evCut2->AddCut(AliReducedVarManager::kNMCtruthJpsi, 1. , 1.);
      
  cout << "run number: " << runNumber << endl;


    //default analysis cut  
//  evCut1->AddCut(AliReducedVarManager::kIsSPDPileupMultBins, .9, 1.1, kTRUE);   // SPD pileup rejection in multiplicity bins
//  evCut1->AddCut(AliReducedVarManager::kINT7Triggered, 0.1, 2., kFALSE  );   // only MB events   
//  evCut1->AddCut(AliReducedVarManager::kNVtxContributors, 0., .9, kTRUE);  
//  evCut1->AddCut(AliReducedVarManager::kSPDntracklets, 0., .9, kTRUE);    
   
// INEL>0 cut
//   evCut1->AddCut(AliReducedVarManager::kNch10, 0., .9, kTRUE);
  
  processor->AddEventCut(evCut1);
  processor->AddEventCut(evCut2);
  // Set track cuts

if( SYSTEMATICS){
    
  processor->AddTrackCut( SetTrackCuts("default") );
  processor->AddTrackCut( SetTrackCuts("strictPion1",   .8, 1., 3.,70.,3., 4., -2., 3., 3.25) ) ;
  processor->AddTrackCut( SetTrackCuts("strictPion2",   .8, 1., 3.,70.,3., 4., -2., 3., 3.5) ) ;
  processor->AddTrackCut( SetTrackCuts("loosePion1",   .8, 1., 3.,70.,3., 4., -2., 3., 2.75) ) ;
  processor->AddTrackCut( SetTrackCuts("loosePion2",   .8, 1., 3.,70.,3., 4., -2., 3., 2.5) ) ;
  processor->AddTrackCut( SetTrackCuts("strictProton1",   .8, 1., 3.,70.,3., 4., -2., 3., 3., 3.75) ) ;
  processor->AddTrackCut( SetTrackCuts("strictProton2",   .8, 1., 3.,70.,3., 4., -2., 3., 3., 4.) ) ;
  processor->AddTrackCut( SetTrackCuts("looseProton1",   .8, 1., 3.,70.,3., 4., -2., 3., 3., 3.25) ) ;
  processor->AddTrackCut( SetTrackCuts("looseProton2",   .8, 1., 3.,70.,3., 4., -2., 3., 3., 3.) ) ;
  processor->AddTrackCut( SetTrackCuts("strictElectronUp1",   .8, 1., 3.,70., 3., 4., -2., 2.75) ) ;
  processor->AddTrackCut( SetTrackCuts("strictElectronUp2",   .8, 1., 3.,70., 3., 4., -2., 2.5) ) ;
  processor->AddTrackCut( SetTrackCuts("looseElectronUp1",   .8, 1., 3.,70., 3., 4., -2., 3.25) ) ;
  processor->AddTrackCut( SetTrackCuts("looseElectronUp2",   .8, 1., 3.,70., 3., 4., -2., 3.5) ) ;
  processor->AddTrackCut( SetTrackCuts("strictElectronDown1",   .8, 1., 3.,70., 3., 4., -1.75) ) ;
  processor->AddTrackCut( SetTrackCuts("strictElectronDown2",   .8, 1., 3.,70., 3., 4., -1.5) ) ;
  processor->AddTrackCut( SetTrackCuts("looseElectronDown1",   .8, 1., 3.,70., 3., 4., -2.25) ) ;
  processor->AddTrackCut( SetTrackCuts("looseElectronDown2",   .8, 1., 3.,70., 3., 4., -2.5) ) ;
  processor->AddTrackCut( SetTrackCuts("strictChi21",   .8, 1., 3.,70., 3., 3.) ) ;
  processor->AddTrackCut( SetTrackCuts("strictChi22",   .8, 1., 3.,70., 3., 2.5) ) ;
  processor->AddTrackCut( SetTrackCuts("looseChi2",   .8, 1., 3.,70., 3., 10.) ) ;
  processor->AddTrackCut( SetTrackCuts("strictnclsTPC1",   .8, 1., 3.,80.) ) ;
  processor->AddTrackCut( SetTrackCuts("strictnclsTPC2",   .8, 1., 3.,90.) ) ;
  processor->AddTrackCut( SetTrackCuts("loosenclsTPC",   .8, 1., 3.,50.) ) ;
  processor->AddTrackCut( SetTrackCuts("strictnclsITS",   .8, 1., 3.,70., 4.) ) ;
  processor->AddTrackCut( SetTrackCuts("loosenclsITS",   .8, 1., 3.,70., 0.) ) ;
  processor->AddTrackCut( SetTrackCuts("strictDCAxy1",   .8, .5) ) ;
  processor->AddTrackCut( SetTrackCuts("strictDCAxy2",   .8, .2) ) ;
  processor->AddTrackCut( SetTrackCuts("looseDCAxy",   .8, 3.) ) ;
  processor->AddTrackCut( SetTrackCuts("strictDCAz1",   .8, 1., 2.) ) ;
  processor->AddTrackCut( SetTrackCuts("strictDCAz2",   .8, 1., 1.) ) ;
  processor->AddTrackCut( SetTrackCuts("looseDCAz",   .8, 1., 5.) ) ;
  processor->AddTrackCut( SetTrackCuts("noKinkRejection",   .8, 1., 3.,70., 3., 4., -2., 3., 3., 3.5, 0) ) ;
  processor->AddTrackCut( SetTrackCuts("kinkMotherRejection",  .8, 1., 3.,70., 3., 4., -2., 3., 3., 3.5, 2) ) ;
  processor->AddTrackCut( SetTrackCuts("SPDfirst",   .8, 1., 3.,70., 3., 4., -2., 3., 3., 3.5, 1,2) ) ;
  processor->AddTrackCut( SetTrackCuts("SPDboth",   .8, 1., 3.,70., 3., 4., -2., 3., 3., 3.5, 1,3) ) ;
  processor->AddTrackCut( SetTrackCuts("lowPt1",   .8, 1., 3.,70., 3., 4., -2., 3., 3., 3.5, 1,1, 0.9) ) ;
  processor->AddTrackCut( SetTrackCuts("lowPt2",   .8, 1., 3.,70., 3., 4., -2., 3., 3., 3.5, 1,1, 0.8) ) ;
  processor->AddTrackCut( SetTrackCuts("highPt1",   .8, 1., 3.,70., 3., 4., -2., 3., 3., 3.5, 1,1, 1.1) ) ;
  processor->AddTrackCut( SetTrackCuts("highPt2",   .8, 1., 3.,70., 3., 4., -2., 3., 3., 3.5, 1,1, 1.2) ) ;
  processor->AddTrackCut( SetTrackCuts("narrowEta1",   .75) ) ;
  processor->AddTrackCut( SetTrackCuts("narrowEta2",   .7) ) ;
  processor->AddTrackCut( SetTrackCuts("wideEta1",   .85) ) ;
  processor->AddTrackCut( SetTrackCuts("wideEta2",   .9) ) ;
  
  
  
  
  
  
  
}
else{
  
  AliReducedTrackCut* trackCut00 = new AliReducedTrackCut("tracking0","puretracking");
  processor->AddTrackCut(trackCut00);
  
  
    
  AliReducedTrackCut* trackCut0 = new AliReducedTrackCut("tracking","tracking");
  trackCut0->SetRequestITSrefit();
  trackCut0->SetRequestTPCrefit();
  trackCut0->SetRejectKinks();
  trackCut0->AddCut(AliReducedVarManager::kPt, 1.,100.0);
  trackCut0->AddCut(AliReducedVarManager::kEta, -0.8, 0.8);
  trackCut0->AddCut(AliReducedVarManager::kDcaXY, -1., 1.);
  trackCut0->AddCut(AliReducedVarManager::kDcaZ, -3., 3.);
  trackCut0->AddCut(AliReducedVarManager::kTPCncls, 70.,160.0);
  trackCut0->AddCut(AliReducedVarManager::kTPCchi2, 0., 4.);
  trackCut0->AddCut(AliReducedVarManager::kITSncls, 3., 9.);
    processor->AddTrackCut(trackCut0);
  
  
  
  AliReducedTrackCut* trackCut1 = new AliReducedTrackCut("relaxedPID","relaxedPID");
  trackCut1->AddCut(AliReducedVarManager::kPt, 1.,100.0);
  trackCut1->AddCut(AliReducedVarManager::kEta, -0.8, 0.8);
  trackCut1->AddCut(AliReducedVarManager::kDcaXY, -1., 1.);
  trackCut1->AddCut(AliReducedVarManager::kDcaZ, -3., 3.);
  trackCut1->AddCut(AliReducedVarManager::kTPCncls, 70.,160.0);
  trackCut1->AddCut(AliReducedVarManager::kTPCchi2, 0., 4.);
  trackCut1->AddCut(AliReducedVarManager::kITSncls, 3., 9.);
  trackCut1->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion, 3., 1.0e+30   );
  trackCut1->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron, -2., 3.);
  trackCut1->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kProton, 3.5, 1.0e+30);
  trackCut1->SetRejectKinks();
  trackCut1->SetRequestITSrefit();
  trackCut1->SetRequestTPCrefit();
  trackCut1->SetRequestSPDany();
  processor->AddTrackCut(trackCut1);
  



  AliReducedTrackCut* trackCut11 = new AliReducedTrackCut("moreRelaxedPID","moreRelaxedPID");
  trackCut11->AddCut(AliReducedVarManager::kPt, 1.,100.0);
  trackCut11->AddCut(AliReducedVarManager::kEta, -0.8, 0.8);
  trackCut11->AddCut(AliReducedVarManager::kDcaXY, -1., 1.);
  trackCut11->AddCut(AliReducedVarManager::kDcaZ, -3., 3.);
  trackCut11->AddCut(AliReducedVarManager::kTPCncls, 70.,160.0);
  trackCut11->AddCut(AliReducedVarManager::kTPCchi2, 0., 4.);
  trackCut11->AddCut(AliReducedVarManager::kITSncls, 3., 9.);
  trackCut11->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion, 3., 1.0e+30   );
  trackCut11->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron, -2., 3.);
  trackCut11->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kProton, 3.5, 1.0e+30);
  trackCut11->SetRejectKinks();
  trackCut11->SetRequestITSrefit();
  trackCut11->SetRequestTPCrefit();
  trackCut11->SetRequestSPDany();
  processor->AddTrackCut(trackCut11);




   
     AliReducedTrackCut* noDCAcut = new AliReducedTrackCut("noDCAcut","noDCAcut");
  noDCAcut->AddCut(AliReducedVarManager::kPt, 1.,100.0);
  noDCAcut->AddCut(AliReducedVarManager::kEta, -0.8, 0.8);
//   noDCAcut->AddCut(AliReducedVarManager::kDcaXY, -1., 1.);
//   noDCAcut->AddCut(AliReducedVarManager::kDcaZ, -3., 3.);
  noDCAcut->AddCut(AliReducedVarManager::kTPCncls, 70.,160.0);
  noDCAcut->AddCut(AliReducedVarManager::kTPCchi2, 0., 4.);
  noDCAcut->AddCut(AliReducedVarManager::kITSncls, 3., 9.);
  noDCAcut->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion, 3., 1.0e+30   );
  noDCAcut->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron, -2., 3.);
  noDCAcut->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kProton, 3.5, 1.0e+30);
  noDCAcut->SetRejectKinks();
  noDCAcut->SetRequestITSrefit();
  noDCAcut->SetRequestTPCrefit();
  noDCAcut->SetRequestSPDany();
//    processor->AddTrackCut(noDCAcut);
   
     AliReducedTrackCut* noKinkReject = new AliReducedTrackCut("noKinkReject","noKinkReject");
  noKinkReject->AddCut(AliReducedVarManager::kPt, 1.,100.0);
  noKinkReject->AddCut(AliReducedVarManager::kEta, -0.8, 0.8);
  noKinkReject->AddCut(AliReducedVarManager::kDcaXY, -1., 1.);
  noKinkReject->AddCut(AliReducedVarManager::kDcaZ, -3., 3.);
  noKinkReject->AddCut(AliReducedVarManager::kTPCncls, 70.,160.0);
  noKinkReject->AddCut(AliReducedVarManager::kTPCchi2, 0., 4.);
  noKinkReject->AddCut(AliReducedVarManager::kITSncls, 3., 9.);
  noKinkReject->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion, 3., 1.0e+30   );
  noKinkReject->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron, -2., 3.);
  noKinkReject->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kProton, 3.5, 1.0e+30);
//   noKinkReject->SetRejectKinks();
  noKinkReject->SetRequestITSrefit();
  noKinkReject->SetRequestTPCrefit();
  noKinkReject->SetRequestSPDany();
//    processor->AddTrackCut(noKinkReject);
   
  
  
  AliReducedTrackCut* spdHit = new AliReducedTrackCut("spdHit","spdHit");
  spdHit->SetRejectKinks();
  spdHit->AddCut(AliReducedVarManager::kPt, 1.,100.0);
  spdHit->AddCut(AliReducedVarManager::kEta, -0.8, 0.8);
  spdHit->AddCut(AliReducedVarManager::kDcaXY, -1., 1.);
  spdHit->AddCut(AliReducedVarManager::kDcaZ, -3., 3.);
  spdHit->AddCut(AliReducedVarManager::kTPCncls, 70.,160.0);
  spdHit->AddCut(AliReducedVarManager::kTPCchi2, 0., 4.);
  spdHit->AddCut(AliReducedVarManager::kITSncls, 3., 9.);
  spdHit->SetRequestITSrefit();
  spdHit->SetRequestTPCrefit();
  spdHit->SetRequestSPDany();
   processor->AddTrackCut(spdHit);
  
  AliReducedTrackCut* trackNoProtExcl = new AliReducedTrackCut("noProtExcl","noProtExcl");
  trackNoProtExcl->AddCut(AliReducedVarManager::kPt, 1.,100.0);
  trackNoProtExcl->AddCut(AliReducedVarManager::kEta, -0.8, 0.8);
  trackNoProtExcl->AddCut(AliReducedVarManager::kDcaXY, -1., 1.);
  trackNoProtExcl->AddCut(AliReducedVarManager::kDcaZ, -3., 3.);
  trackNoProtExcl->AddCut(AliReducedVarManager::kTPCncls, 70.,160.0);
  trackNoProtExcl->AddCut(AliReducedVarManager::kTPCchi2, 0., 4.);
  trackNoProtExcl->AddCut(AliReducedVarManager::kITSncls, 3., 9.);
  trackNoProtExcl->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion, 3., 1.0e+30   );
  trackNoProtExcl->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron, -2., 3.);
//   trackNoProtExcl->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kProton, 3.5, 1.0e+30);
  trackNoProtExcl->SetRejectKinks();
  trackNoProtExcl->SetRequestITSrefit();
  trackNoProtExcl->SetRequestTPCrefit();
   trackNoProtExcl->SetRequestSPDany();
//     processor->AddTrackCut(trackNoProtExcl);
  
  AliReducedTrackCut* trackNoPionExcl = new AliReducedTrackCut("noPionExcl","noPionExcl");
  trackNoPionExcl->AddCut(AliReducedVarManager::kPt, 1.,100.0);
  trackNoPionExcl->AddCut(AliReducedVarManager::kEta, -0.8, 0.8);
  trackNoPionExcl->AddCut(AliReducedVarManager::kDcaXY, -1., 1.);
  trackNoPionExcl->AddCut(AliReducedVarManager::kDcaZ, -3., 3.);
  trackNoPionExcl->AddCut(AliReducedVarManager::kTPCncls, 70.,160.0);
  trackNoPionExcl->AddCut(AliReducedVarManager::kTPCchi2, 0., 4.);
  trackNoPionExcl->AddCut(AliReducedVarManager::kITSncls, 3., 9.);
//   trackNoPionExcl->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion, 3., 1.0e+30   );
  trackNoPionExcl->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron, -2., 3.);
  trackNoPionExcl->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kProton, 3.5, 1.0e+30);
  trackNoPionExcl->SetRejectKinks();
  trackNoPionExcl->SetRequestITSrefit();
  trackNoPionExcl->SetRequestTPCrefit();
   trackNoPionExcl->SetRequestSPDany();
    processor->AddTrackCut(trackNoPionExcl);
  
  
  AliReducedTrackCut* trackCutGammas = new AliReducedTrackCut("gammaCuts","gammaCuts");
//   trackCutGammas->AddCut(AliReducedVarManager::kPt, 1.,100.0);
  trackCutGammas->AddCut(AliReducedVarManager::kEta, -0.8, 0.8);
  trackCutGammas->AddCut(AliReducedVarManager::kDcaXY, -1., 1.);
  trackCutGammas->AddCut(AliReducedVarManager::kDcaZ, -3., 3.);
  trackCutGammas->AddCut(AliReducedVarManager::kTPCncls, 70.,160.0);
  trackCutGammas->AddCut(AliReducedVarManager::kTPCchi2, 0., 4.);
//   trackCutGammas->AddCut(AliReducedVarManager::kITSncls, 3., 9.);
//   trackCutGammas->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kProton, 3.5, 1.0e+30);
//   trackCutGammas->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kKaon, -3.5, 1.0e+30);
  trackCutGammas->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion, 3., 1.0e+30   );
  trackCutGammas->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron, -3., 3.);
//   trackCutGammas->AddCut(AliReducedVarManager::kTOFbeta, .9, 1.1,kFALSE, AliReducedVarManager::kTPCnSig+AliReducedVarManager::kProton, -3.5,  3.5);
//   trackCutGammas->AddCut(AliReducedVarManager::kTOFbeta, .9, 1.1,kFALSE, AliReducedVarManager::kTPCnSig+AliReducedVarManager::kKaon, -3.5,  3.5);
  trackCutGammas->SetRejectKinks();
  trackCutGammas->SetRequestITSrefit();
  trackCutGammas->SetRequestTPCrefit();
//   trackCutGammas->SetRequestSPDany();
//    processor->AddTrackCut(trackCutGammas);
  
  
   
   
  
  AliReducedTrackCut* trackCut2 = new AliReducedTrackCut("TOF","TOF");
  trackCut2->AddCut(AliReducedVarManager::kPt, 1.,100.0);
  trackCut2->AddCut(AliReducedVarManager::kEta, -0.8, 0.8);
  trackCut2->AddCut(AliReducedVarManager::kDcaXY, -1., 1.);
  trackCut2->AddCut(AliReducedVarManager::kDcaZ, -3., 3.);
  trackCut2->AddCut(AliReducedVarManager::kTPCncls, 70.,160.0);
  trackCut2->AddCut(AliReducedVarManager::kTPCchi2, 0., 4.);
  trackCut2->AddCut(AliReducedVarManager::kITSncls, 3., 9.);
  trackCut2->AddCut(AliReducedVarManager::kTOFbeta, .01, 9.);
  trackCut2->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kProton, 3.5, 1.0e+30);
  trackCut2->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion, 3., 1.0e+30   );
  trackCut2->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron, -2., 3.);
  trackCut2->SetRejectKinks();
  trackCut2->SetRequestITSrefit();
  trackCut2->SetRequestTPCrefit();
  trackCut2->SetRequestSPDany();
//    processor->AddTrackCut(trackCut2);
  
  
  AliReducedTrackCut* trackSPDboth = new AliReducedTrackCut("noTOF","noTOF");
  trackSPDboth->AddCut(AliReducedVarManager::kPt, 1.,100.0);
  trackSPDboth->AddCut(AliReducedVarManager::kEta, -0.8, 0.8);
  trackSPDboth->AddCut(AliReducedVarManager::kDcaXY, -1., 1.);
  trackSPDboth->AddCut(AliReducedVarManager::kDcaZ, -3., 3.);
  trackSPDboth->AddCut(AliReducedVarManager::kTPCncls, 70.,160.0);
  trackSPDboth->AddCut(AliReducedVarManager::kTPCchi2, 0., 4.);
  trackSPDboth->AddCut(AliReducedVarManager::kITSncls, 3., 9.);
  trackSPDboth->AddCut(AliReducedVarManager::kTOFbeta, .01, 9., kTRUE);
  trackSPDboth->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kProton, 3.5, 1.0e+30);
  trackSPDboth->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion, 3., 1.0e+30   );
  trackSPDboth->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron, -2., 3.);
  trackSPDboth->SetRejectKinks();
  trackSPDboth->SetRequestITSrefit();
  trackSPDboth->SetRequestTPCrefit();
  trackSPDboth->SetRequestSPDany();
//    processor->AddTrackCut(trackSPDboth);
  
  
  
  AliReducedTrackCut* trackCutStraight = new AliReducedTrackCut("straight","straight");
  trackCutStraight->AddCut(AliReducedVarManager::kPt, 1.2,100.0);
  trackCutStraight->AddCut(AliReducedVarManager::kEta, -0.8, 0.8);
  trackCutStraight->AddCut(AliReducedVarManager::kDcaXY, -1., 1.);
  trackCutStraight->AddCut(AliReducedVarManager::kDcaZ, -3., 3.);
  trackCutStraight->AddCut(AliReducedVarManager::kTPCncls, 70.,160.0);
  trackCutStraight->AddCut(AliReducedVarManager::kTPCchi2, 0., 4.);
  trackCutStraight->AddCut(AliReducedVarManager::kITSncls, 3., 9.);
//   trackCutStraight->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kProton, 3.5, 1.0e+30);
  trackCutStraight->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion, 3., 1.0e+30   );
  trackCutStraight->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron, -2., 3.);
  trackCutStraight->SetRejectKinks();
  trackCutStraight->SetRequestITSrefit();
  trackCutStraight->SetRequestTPCrefit();
  trackCutStraight->SetRequestSPDany();
//    processor->AddTrackCut(trackCutStraight);
  
  
  
  AliReducedTrackCut* trackCutLoose = new AliReducedTrackCut("loosePID","loosePID");
  trackCutLoose->AddCut(AliReducedVarManager::kPt, 1.,100.0);
  trackCutLoose->AddCut(AliReducedVarManager::kEta, -0.8, 0.8);
  trackCutLoose->AddCut(AliReducedVarManager::kDcaXY, -1., 1.);
  trackCutLoose->AddCut(AliReducedVarManager::kDcaZ, -3., 3.);
  trackCutLoose->AddCut(AliReducedVarManager::kTPCncls, 70.,160.0);
  trackCutLoose->AddCut(AliReducedVarManager::kTPCchi2, 0., 4.);
  trackCutLoose->AddCut(AliReducedVarManager::kITSncls, 3., 9.);
  trackCutLoose->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kProton, 3., 1.0e+30);
  trackCutLoose->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion, 3., 1.0e+30   );
  trackCutLoose->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron, -2., 3.);
  trackCutLoose->SetRejectKinks();
  trackCutLoose->SetRequestITSrefit();
  trackCutLoose->SetRequestTPCrefit();
  trackCutLoose->SetRequestSPDany();
//    processor->AddTrackCut(trackCutLoose);
 
   




}
   
 
   
        AliReducedTrackCut* prefTrackCutSoft = new AliReducedTrackCut("prefCutPtSoft","prefCutPtSoft");
      prefTrackCutSoft->AddCut(AliReducedVarManager::kPt, 0.2, 100.0);
      prefTrackCutSoft->AddCut(AliReducedVarManager::kEta, -.8, .8);
      prefTrackCutSoft->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron, -3., 3.0);
      prefTrackCutSoft->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion, 3., 1e30);
      prefTrackCutSoft->AddCut(AliReducedVarManager::kDcaXY, -1.,1.);
      prefTrackCutSoft->AddCut(AliReducedVarManager::kDcaZ, -3.0,3.0);
      prefTrackCutSoft->SetRequestITSrefit();
      prefTrackCutSoft->SetRequestTPCrefit();
      prefTrackCutSoft->AddCut(AliReducedVarManager::kTPCncls, 70.,160.0);
      prefTrackCutSoft->AddCut(AliReducedVarManager::kTPCchi2, 0., 4.);  
   
   
        AliReducedTrackCut* prefTrackCutSoft2 = new AliReducedTrackCut("prefCutPtSoft2","prefCutPtSoft2");
      prefTrackCutSoft2->AddCut(AliReducedVarManager::kPt, 0.2, 100.0);
      prefTrackCutSoft2->AddCut(AliReducedVarManager::kEta, -.8, .8);
      prefTrackCutSoft2->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron, -3., 3.0);
      prefTrackCutSoft2->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion, 3., 1e30);
      prefTrackCutSoft2->AddCut(AliReducedVarManager::kDcaXY, -1.,1.);
      prefTrackCutSoft2->AddCut(AliReducedVarManager::kDcaZ, -3.0,3.0);
      prefTrackCutSoft2->SetRequestITSrefit();
      prefTrackCutSoft2->SetRequestTPCrefit();
      prefTrackCutSoft2->AddCut(AliReducedVarManager::kTPCncls, 70.,160.0);
      prefTrackCutSoft2->AddCut(AliReducedVarManager::kTPCchi2, 0., 4.);  
   
   
   
  if(prefilterType){



 
  
      
      
      
//       prefTrackCutSoft->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kProton, -3.5,  3.5, kTRUE);
      
      
      
        
      AliReducedTrackCut* prefTrackCutStrong = new AliReducedTrackCut("prefCutPtStrong","prefCutPtStrong");
      prefTrackCutStrong->AddCut(AliReducedVarManager::kPt, 1.,100.0);
      prefTrackCutStrong->AddCut(AliReducedVarManager::kEta, -0.8, 0.8);
      prefTrackCutStrong->AddCut(AliReducedVarManager::kDcaXY, -1.,1.);
      prefTrackCutStrong->AddCut(AliReducedVarManager::kDcaZ, -3.0,3.0);
      prefTrackCutStrong->AddCut(AliReducedVarManager::kTPCncls, 70.,160.0);
      prefTrackCutStrong->AddCut(AliReducedVarManager::kTPCchi2, 0., 4.);
      prefTrackCutStrong->AddCut(AliReducedVarManager::kITSncls, 3., 9.);
      prefTrackCutStrong->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kProton, 3.5, 1.0e+30);
      prefTrackCutStrong->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion, 3., 1.0e+30   );
      prefTrackCutStrong->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron, -2., 3.);
      prefTrackCutStrong->SetRejectKinks();
      prefTrackCutStrong->SetRequestITSrefit();
      prefTrackCutStrong->SetRequestTPCrefit();
      prefTrackCutStrong->SetRequestSPDany();
        
        
        

    if(prefilterType == 5 || prefilterType==8)  processor->AddPrefilterTrackCut(prefTrackCutStrong);
    else      processor->AddPrefilterTrackCut(prefTrackCutSoft);
    
    if( prefilterType > 3 ){
      
      
      AliReducedTrackCut* prefPairCutPhiVDca = new AliReducedTrackCut("prefPairCutPhiVDca","prefilter pair cut");
      if( prefilterType == 7 ||  prefilterType == 4   ||  prefilterType == 8)  prefPairCutPhiVDca->AddCut(AliReducedVarManager::kMass, 0., .05 , kTRUE);
//       else prefPairCutPhiVDca->AddCut(AliReducedVarManager::kMassDcaPtCorr, -.1, .1 , kTRUE);
      //else prefPairCutPhiVDca->AddCut(AliReducedVarManager::kMassDcaPtCorr, -0.02, .02, kTRUE);
      else prefPairCutPhiVDca->AddCut(AliReducedVarManager::kMass, -0.04, .04, kTRUE);
      processor->AddPrefilterPairCut(prefPairCutPhiVDca);
    
     if( prefilterType == 6  || prefilterType == 5 || prefilterType == 7 ||  prefilterType == 8  ){

      AliReducedTrackCut* prefCutPairType = new AliReducedTrackCut("prefCutPairType","prefilter pair cut2");
      prefCutPairType->AddCut(AliReducedVarManager::kPairType, .9, 1.1, kTRUE );
      processor->AddPrefilterPairCut(prefCutPairType);
      
      
//       AliReducedTrackCut* prefCutPhiV = new AliReducedTrackCut("prefCutPhiV","prefilter pair cut2");  
//       if(runNumber < 254604  )prefCutPhiV->AddCut(AliReducedVarManager::kPairPhiV, 2.44, 3.15, kTRUE );
//       else prefCutPhiV->AddCut(AliReducedVarManager::kPairPhiV, 0., 0.7, kTRUE
//       );
// 
//       
//       processor->AddPrefilterPairCut(prefCutPhiV);

     }

    /* 
     
     processor->AddPrefilterTrackCut2(prefTrackCutSoft2);
     
     AliReducedTrackCut* prefPairCutMass2 = new AliReducedTrackCut("prefPairCutMass2","prefilter pair cut");
//      prefPairCutMass2->AddCut(AliReducedVarManager::kMass, 0., 1.2, kTRUE);
     prefPairCutMass2->AddCut(AliReducedVarManager::kMass, 0., 0., kTRUE);
//      prefPairCutMass2->AddCut(AliReducedVarManager::kMassDcaPtCorr, -.1, .1 , kTRUE);
     processor->AddPrefilterPairCut2(prefPairCutMass2);
     
//       AliReducedTrackCut* prefCutPairType2 = new AliReducedTrackCut("prefCutPairType2","prefilter pair cut2");
//       prefCutPairType2->AddCut(AliReducedVarManager::kPairType, .9, 1.1, kFALSE );
//       processor->AddPrefilterPairCut2(prefCutPairType2);
     
     */
     
     
 
    }
      
      else{
      
    // //  // only apply on opposite-sign pairs
     AliReducedTrackCut* prefCutPairType = new AliReducedTrackCut("prefCutPairType","prefilter pair cut2");
     prefCutPairType->AddCut(AliReducedVarManager::kPairType, .9, 1.1, kTRUE );
     processor->AddPrefilterPairCut(prefCutPairType);
     
// // pair DCA cut -> if too large than random combination
      AliReducedTrackCut* prefPairCutDca = new AliReducedTrackCut("prefPairCutDca","prefilter pair cut");
      prefPairCutDca->AddCut(AliReducedVarManager::kPairDcaXYSqrt, 0.0, 1., kTRUE );
      processor->AddPrefilterPairCut(prefPairCutDca);
      
// wide mass cut: Dalitz electrons
//     AliReducedTrackCut* prefPairCutMassWide = new AliReducedTrackCut("prefPairCutMassWide","prefilter pair cut");
//     prefPairCutMassWide->AddCut(AliReducedVarManager::kMass, 0., 0.1  ,kTRUE);
//     processor->AddPrefilterPairCut( prefPairCutMassWide );
      }
      

    if(prefilterType == 1){
      
      
      AliReducedTrackCut* prefPairCutMassCorr = new AliReducedTrackCut("prefPairCutMassCorr","prefilter pair cut");
      prefPairCutMassCorr->AddCut( AliReducedVarManager::kMassDcaPtCorr, -0.01, .02 ,kTRUE  );
      processor->AddPrefilterPairCut(prefPairCutMassCorr);  
      
      
      AliReducedTrackCut* prefPairCutPhiV = new AliReducedTrackCut("prefPairCutPhiV","prefilter pair cut");
      prefPairCutPhiV->AddCut(   AliReducedVarManager::kPairPhiV, 0.0, 1. , kTRUE);
      processor->AddPrefilterPairCut(prefPairCutPhiV);
     
    }
    
    else if(prefilterType == 2){
      
      // // // wide cut on mass -> Dalitz electrons
//       

// // pair DCA cut -> if too large than random combination
      AliReducedTrackCut* prefPairCutDca = new AliReducedTrackCut("prefPairCutDca","prefilter pair cut");
      prefPairCutDca->AddCut(AliReducedVarManager::kPairDcaXYSqrt, 0.0, .5, kTRUE );
      processor->AddPrefilterPairCut(prefPairCutDca);

      
    }
    
    else if(prefilterType == 3){
     //    
// // // cut on phiV DCA dependent
      AliReducedTrackCut* prefPairCutPhiVDca = new AliReducedTrackCut("prefPairCutPhiVDca","prefilter pair cut");
      prefPairCutPhiVDca->AddCut( AliReducedVarManager::kMassDcaPtCorr, -0.02, .02 ,kTRUE/* AliReducedVarManager::kPairPhiV, 0., 1. */);
      prefPairCutPhiVDca->AddCut(AliReducedVarManager::kMass, 0., 0.1 , kTRUE ,AliReducedVarManager::kPairDcaXYSqrt, 0.0, .4  );
//       prefPairCutPhiVDca->AddCut(   AliReducedVarManager::kPairPhiV, 0., 1. , kTRUE, AliReducedVarManager::kPairDcaXYSqrt, .5, 1.);
//         prefPairCutPhiVDca->AddCut( AliReducedVarManager::kPairDcaXYSqrt, 0.0, .5, kTRUE, AliReducedVarManager::kPairPhiV, 1., 4. );
      processor->AddPrefilterPairCut(prefPairCutPhiVDca);
      
      
     
//     AliReducedTrackCut* prefPairCutMassWide = new AliReducedTrackCut("prefPairCutMassWide","prefilter pair cut");
//     prefPairCutMassWide->AddCut(AliReducedVarManager::kMass, 0., 0.1 , kTRUE    );
//     processor->AddPrefilterPairCut( prefPairCutMassWide );

    }
     
  }
     
  // Set pair cuts
   AliReducedTrackCut* pairCut1 = new AliReducedTrackCut("Ptpair","Pt pair selection");
   pairCut1->AddCut(AliReducedVarManager::kRap, -0.9, 0.9);
    pairCut1->AddCut(AliReducedVarManager::kPt, 0.,6.);
processor->AddPairCut(pairCut1);

#ifdef TRKBINS
    Int_t multEstimator = AliReducedVarManager::GetCorrectedMultiplicity( 
      AliReducedVarManager::kSPDntracklets
      ,AliReducedVarManager::kVertexCorr
  , AliReducedVarManager::kMaximumMultiplicity
//        ,AliReducedVarManager::kPoissonSmearing
   );

#endif
#ifdef TRKBINSRAW
    Int_t multEstimator = AliReducedVarManager::GetCorrectedMultiplicity( 
      AliReducedVarManager::kSPDntracklets
//       ,AliReducedVarManager::kVertexCorr
//   , AliReducedVarManager::kMaximumMultiplicity
//        ,AliReducedVarManager::kPoissonSmearing
   );

#endif
    
    
#ifdef TRK08BINS
    Int_t multEstimator = AliReducedVarManager::GetCorrectedMultiplicity( 
      AliReducedVarManager::kSPDntracklets08
      ,AliReducedVarManager::kVertexCorr
  , AliReducedVarManager::kMaximumMultiplicity
//        ,AliReducedVarManager::kPoissonSmearing
   );

#endif
    
    
    
#ifdef TRK16BINS
    Int_t multEstimator = AliReducedVarManager::GetCorrectedMultiplicity( 
      AliReducedVarManager::kSPDntracklets16
      ,AliReducedVarManager::kVertexCorr
  , AliReducedVarManager::kMaximumMultiplicity
//        ,AliReducedVarManager::kPoissonSmearing
   );

#endif
    
    
    
   #ifdef TOTALBINS
Int_t multEstimator = AliReducedVarManager::kTotalMultiplicity;

#endif 
    
    
    #ifdef VZEROONLINEBINS
    Int_t multEstimator = AliReducedVarManager::kMultEstimatorOnlineV0M;

#endif
    
   
#ifdef VZEROBINS   
   Int_t multEstimator = AliReducedVarManager::GetCorrectedMultiplicity( 
     AliReducedVarManager::kVZEROTotalMult
     ,AliReducedVarManager::kRunCorr
     ,AliReducedVarManager::kMaximumMultiplicity /*,AliReducedVarManager::kPoissonSmearing*/
  );

#endif 
   
   
#ifdef VZEROACBINS   
   Int_t multEstimator = AliReducedVarManager::GetCorrectedMultiplicity( 
     AliReducedVarManager::kVZEROACTotalMult
     ,AliReducedVarManager::kRunCorr
     ,AliReducedVarManager::kMaximumMultiplicity /*,AliReducedVarManager::kPoissonSmearing*/
  );

     
     
#endif  
   
#ifdef VZEROCORRBINS   
   Int_t multEstimator = AliReducedVarManager::kVZEROcorrected;
     
#endif   
   
   

   
   
   
   
   
//    
//    Int_t multEstimator =  AliReducedVarManager::kVZEROTotalMult;
   
//    Int_t multEstimator = AliReducedVarManager::kMultEstimatorOnlineV0M;
//    Int_t multEstimator = AliReducedVarManager::kMultEstimatorADM;
//    Int_t multEstimator = AliReducedVarManager::kMultEstimatorRefMult08;
   
   
   
   
   
   
   
 
    
//     Int_t multEstimator = 
//     AliReducedVarManager::GetCorrectedMultiplicity( 
//       AliReducedVarManager::kSPDntracklets
//       ,AliReducedVarManager::kVertexCorr
//   , AliReducedVarManager::kMaximumMultiplicity
// //   ,AliReducedVarManager::kPoissonSmearing
//    );
   

  SetupHistogramManager(processor, prod, runNumbers, multEstimator);
  SetupMixingHandler(processor, multEstimator);
}


//_________________________________________________________________
void DefineHistograms(AliReducedAnalysisJpsi2eeMult* task, TString prod, TString runNumbers /*="LHC10h"*/, Int_t multEstimator) {

  AliHistogramManager* man = task->GetHistogramManager(); 
    TString histClasses = "";
//   histClasses += "EventTag_BeforeCuts;";
//  histClasses += "Event_BeforeCuts;";   
   histClasses += "Event_AfterCuts;";   
//   histClasses += "EventTag_AfterCuts;";
  for(Int_t i=0; i<task->GetNTrackCuts(); ++i) {
    TString cutName = task->GetTrackCutName(i);

//       histClasses += Form("Track+_%s;", cutName.Data());
//       histClasses += Form("Track-_%s;", cutName.Data());

//       histClasses += Form("PairTRPM_%s;", cutName.Data());
//       histClasses += Form("PairSEPP_%s;PairSEPM_%s;PairSEMM_%s;", cutName.Data(), cutName.Data(), cutName.Data());
//       histClasses += Form("PairMEPM_%s;", cutName.Data() );
   if(task->GetRunOverMC()) {
     for(Int_t mcSel=0; mcSel<task->GetNLegCandidateMCcuts(); ++mcSel) {
       histClasses += Form("PairSEPM_%s_%s;", cutName.Data(), task->GetLegCandidateMCcutName(mcSel));
   
 if(!SYSTEMATICS){
//    histClasses += Form("Track_%s_%s;", cutName.Data(), task->GetLegCandidateMCcutName(mcSel));
        }
      }
    }


    
  }
  
  if(task->GetRunOverMC()) {
     for(Int_t mcSel=0; mcSel<task->GetNJpsiMotherMCCuts(); ++mcSel) {
        histClasses += Form("%s_PureMCTruth_BeforeSelection;", task->GetJpsiMotherMCcutName(mcSel));
        histClasses += Form("%s_PureMCTruth_AfterSelection;", task->GetJpsiMotherMCcutName(mcSel));
     }
  }
  
  

  TString classesStr(histClasses);
  TObjArray* arr=classesStr.Tokenize(";");
  
  
  TObjArray* runsArr = runNumbers.Tokenize(";");
  Int_t nRuns = runsArr->GetEntriesFast();
  cout << "number of runs: " << nRuns << endl;
  //TString periods = "16d;16e;16g;16h;16i;16j;16k;16l;16o;16p;17h;17i;17j;17k;17l;17m;17o;17r;18b;18d;18e;18f;18g;18h;18i;18j;18k;18l;18m;18n;18o;18p";
  TString periods = "2016d;16e;16g;16h--;16h++;16i;16j;16k(pass2);16l(pass2);16o;16p;2017h;17i;17j;17k;17l;17m;17o;17r;2018b;18d;18e;18f;18g;18h;18i;18j;18k;18l;18m;18n;18o;18p";

  TObjArray* periodsArr = periods.Tokenize(";");
  Int_t nPeriods = periodsArr->GetEntriesFast();
  
  
  
  
  
//       const Int_t kNperiodBins = 12;
//       Double_t periodBins[kNperiodBins] = {0.,1.,2.,3.,4.,5.,6.,7.,8.,9.,10., 11. };
  
//      const Int_t kNperiodBins = 2;
//      Double_t periodBins[kNperiodBins] = {0.,/*1.,2.,3.,4.,5.,6.,7.,8.,9.,10.,*/ 11. };
      
      const Int_t kNMBBins = 3;
      Double_t mbBins[kNMBBins] = {0.,1.,2.};

      const Int_t kNVtxBins = 2;
      Double_t vtxBins[kNVtxBins] = {  -10., 10.  };
      
//       const Int_t kNVtxBins = 21;
//       Double_t vtxBins[kNVtxBins] = { 
//         -10.,-9., -8., -7., -6.,
//         -5., -4., -3., -2., -1.,
//          0.,  1.,  2.,  3.,  4.,
//          5.,  6.,  7.,  8., 9., 
//          10.  };

    
    
#ifdef VZEROBINS
   const Int_t nMultBinLimits =  19;
   Double_t multBinLimits[nMultBinLimits] ={  
     0.,  50., 
   100.,150.,
   200.,250.,
   300.,350.,
   400.,450.,
   500.,550.,
   600.,650.,
   700.,750.,
   800.,900.,  
   1000.};

#endif
   
       
// #ifdef VZEROCORRBINS
//    const Int_t nMultBinLimits =  25;
//    Double_t multBinLimits[nMultBinLimits] ={  
//         0.,  10.,  20.,  30.,  40., 
//        50.,  60.,  70.,  80.,  90.,
//       100., 110., 120., 130., 140.,
//       150., 160., 170., 180., 190.,
//       200., 210., 220., 230., 240.
//   };
// #endif
   
   
       
#ifdef VZEROACBINS
   const Int_t nMultBinLimits =  19;
   Double_t multBinLimits[nMultBinLimits] ={  
     0.,  50., 
   100.,150.,
   200.,250.,
   300.,350.,
   400.,450.,
   500.,550.,
   600.,650.,
   700.,750.,
   800.,900.,  
   1000.};

   
     const Int_t nMultBinLimitsNormalization = multBinLimits[ nMultBinLimits - 1 ] + 2;
  Double_t multBinLimitsNormalization[nMultBinLimitsNormalization];
  
  for( int i=0; i < nMultBinLimitsNormalization ; ++i  ){
    multBinLimitsNormalization[i] = i /100.;
  }  
  for( int i=0; i < nMultBinLimits ; ++i  ){
    multBinLimits[i] /= 100.;
  }
   
   
   
   
#endif
   
   
   
   
   
#ifdef VZEROABINS      
   const Int_t nMultBinLimits =  11;
   Double_t multBinLimits[nMultBinLimits] ={  
      0., 50., 
      100., 150., 
      200., 250.,
      300.,350.,
      400.,450.,
      500.};
#endif
#ifdef VZEROCBINS       
   const Int_t nMultBinLimits =  11;
   Double_t multBinLimits[nMultBinLimits] ={  
      0., 50., 
      100., 150., 
      200., 250.,
      300.,350.,
      400.,450.,
      500.};
#endif

// #if defined(TRKBINS) || defined(VZEROCORRBINS) || defined(TRK08BINS) || defined(TRK05BINS)|| defined(TRKBINSRAW)
//    const Int_t nMultBinLimits =   32 ;
//    Double_t multBinLimits[nMultBinLimits] ={ 
//       0., 1.,   2.,  3.,  4.,
//       5., 6.,   7.,  8.., 9.,
//      10., 15., 20., 25., 30.,
//      35., 40., 45., 50., 55., 
//      60., 65., 70., 75., 80.,
//      85., 90., 95.,100.,105.,
//      110.,140. };  
// #endif

#if defined(TRKBINS) || defined(VZEROCORRBINS) || defined(TRK08BINS) || defined(TRK05BINS)|| defined(TRKBINSRAW)
   const Int_t nMultBinLimits = 4;
   Double_t multBinLimits[nMultBinLimits] ={ 
      0.,   1.,   2.,  40. };  
#endif
  

#if defined(TOTALBINS) || defined(TRK16BINS)
   const Int_t nMultBinLimits = 43;
   Double_t multBinLimits[nMultBinLimits] ={ 
      0., 1.,   5., 10., 15.,
     20., 25., 30., 35., 40.,
     45., 50., 55., 60., 65., 
     70., 75., 80., 85., 90.,
     95.,100.,105.,110.,115.,
    120.,125.,130.,135.,140.,
    145.,150.,155.,160.,165.,
    170.,175.,180.,185.,190.,
    195.,200.,250.};  


#endif


     
#if !defined( VZEROACBINS) 
  
  const Int_t nMultBinLimitsNormalization = multBinLimits[ nMultBinLimits - 1 ] + 2;
  Double_t multBinLimitsNormalization[nMultBinLimitsNormalization];
  
  for( int i=0; i < nMultBinLimitsNormalization ; ++i  ){
    multBinLimitsNormalization[i] = i - .5;
  }  
  for( int i=0; i < nMultBinLimits ; ++i  ){
    multBinLimits[i] -= .5;
  }
     
#endif
  
  
  
  
  
   
   
  
  Int_t iTrk            = AliReducedVarManager::kSPDntracklets ;
  
  Int_t iTrkCorrMax     = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kSPDntracklets , AliReducedVarManager::kVertexCorr, AliReducedVarManager::kMaximumMultiplicity   );
  Int_t iTrkCorrMin     = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kSPDntracklets , AliReducedVarManager::kVertexCorr, AliReducedVarManager::kMinimumMultiplicity   );
  Int_t iTrkCorrMean    = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kSPDntracklets , AliReducedVarManager::kVertexCorr, AliReducedVarManager::kMeanMultiplicity   );
  
  Int_t iTrkCorrMaxSmear  = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kSPDntracklets , AliReducedVarManager::kVertexCorr, AliReducedVarManager::kMaximumMultiplicity, AliReducedVarManager::kPoissonSmearing   );
  Int_t iTrkCorrMinSmear  = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kSPDntracklets , AliReducedVarManager::kVertexCorr, AliReducedVarManager::kMinimumMultiplicity, AliReducedVarManager::kPoissonSmearing    );
  Int_t iTrkCorrMeanSmear = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kSPDntracklets , AliReducedVarManager::kVertexCorr, AliReducedVarManager::kMeanMultiplicity, AliReducedVarManager::kPoissonSmearing    );
  
  
  

  
  
  
  
  Int_t iTrkEtaCorrMax      = AliReducedVarManager::GetCorrectedMultiplicity(AliReducedVarManager::kSPDnTracklets10EtaVtxCorr, AliReducedVarManager::kVertexCorr, AliReducedVarManager::kMaximumMultiplicity   );
  Int_t iTrkEtaCorrMaxSmear = AliReducedVarManager::GetCorrectedMultiplicity(AliReducedVarManager::kSPDnTracklets10EtaVtxCorr, AliReducedVarManager::kVertexCorr, AliReducedVarManager::kMaximumMultiplicity , AliReducedVarManager::kPoissonSmearing  );
  
  Int_t iV0            =  AliReducedVarManager::kVZEROTotalMult ;
  Int_t iV0A           = AliReducedVarManager::kVZEROATotalMult  ;
  Int_t iV0C           = AliReducedVarManager::kVZEROCTotalMult  ;
  Int_t iV0AC          = AliReducedVarManager::kVZEROACTotalMult ;
  
  
  Int_t iV0GainLossMax     = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kVZEROTotalMult , AliReducedVarManager::kRunCorr, AliReducedVarManager::kMaximumMultiplicity   );
  Int_t iV0AGainLossMax     = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kVZEROATotalMult , AliReducedVarManager::kRunCorr, AliReducedVarManager::kMaximumMultiplicity   );
  Int_t iV0CGainLossMax     = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kVZEROCTotalMult , AliReducedVarManager::kRunCorr, AliReducedVarManager::kMaximumMultiplicity   );
  Int_t iV0ACGainLossMax     = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kVZEROACTotalMult , AliReducedVarManager::kRunCorr, AliReducedVarManager::kMaximumMultiplicity   );
  
  
  
  Int_t iV0CorrMax     = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kVZEROTotalMult , AliReducedVarManager::kVertexCorr, AliReducedVarManager::kMaximumMultiplicity   );
  Int_t iV0CorrMin     = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kVZEROTotalMult , AliReducedVarManager::kVertexCorr, AliReducedVarManager::kMinimumMultiplicity   );
  Int_t iV0CorrMean    = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kVZEROTotalMult , AliReducedVarManager::kVertexCorr, AliReducedVarManager::kMeanMultiplicity   );
  
  Int_t iV0ACorrMax     = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kVZEROATotalMult , AliReducedVarManager::kVertexCorr, AliReducedVarManager::kMaximumMultiplicity   );
  Int_t iV0ACorrMin     = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kVZEROATotalMult , AliReducedVarManager::kVertexCorr, AliReducedVarManager::kMinimumMultiplicity   );
  Int_t iV0ACorrMean    = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kVZEROATotalMult , AliReducedVarManager::kVertexCorr, AliReducedVarManager::kMeanMultiplicity   );
 
  
  Int_t iV0CCorrMax     = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kVZEROCTotalMult , AliReducedVarManager::kVertexCorr, AliReducedVarManager::kMaximumMultiplicity   );
  Int_t iV0CCorrMin     = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kVZEROCTotalMult , AliReducedVarManager::kVertexCorr, AliReducedVarManager::kMinimumMultiplicity   );
  Int_t iV0CCorrMean    = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kVZEROCTotalMult , AliReducedVarManager::kVertexCorr, AliReducedVarManager::kMeanMultiplicity   );
 
   Int_t iV0ACCorrMax     = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kVZEROACTotalMult , AliReducedVarManager::kVertexCorr, AliReducedVarManager::kMaximumMultiplicity   );
 
  
  
  
  
  
  Int_t iV0CorrMaxSmear  = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kVZEROTotalMult , AliReducedVarManager::kVertexCorr, AliReducedVarManager::kMaximumMultiplicity, AliReducedVarManager::kPoissonSmearing   );
  Int_t iV0CorrMinSmear  = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kVZEROTotalMult , AliReducedVarManager::kVertexCorr, AliReducedVarManager::kMinimumMultiplicity, AliReducedVarManager::kPoissonSmearing    );
  Int_t iV0CorrMeanSmear = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kVZEROTotalMult , AliReducedVarManager::kVertexCorr, AliReducedVarManager::kMeanMultiplicity, AliReducedVarManager::kPoissonSmearing    );
  

  
  
  
  
  
  
  
  
  
  
  
  
  cout << "Histogram classes included in the Histogram Manager" << endl;
  for(Int_t iclass=0; iclass<arr->GetEntries(); ++iclass) {
    TString classStr = arr->At(iclass)->GetName();
    man->AddHistClass(classStr.Data());
    // Event wise histograms
    if(classStr.Contains("Event_")) {
      
      cout << classStr.Data() << endl;
      man->AddHistogram(classStr.Data(),"RunID","Run IDs",kFALSE,nRuns, 0., nRuns, AliReducedVarManager::kRunID );
      
            
      man->AddHistogram(classStr.Data(),"NJpsi","Number of MC truth Jpsi",kFALSE,
                        10,0.,10.,AliReducedVarManager::kNMCtruthJpsi);
      man->AddHistogram(classStr.Data(),"NJpsi_legs","Number of MC truth Jpsi passing leg cuts",kFALSE,
                        10,0.,10.,AliReducedVarManager::kNMCtruthJpsiLegs);

      

      
      
      

      
      if(  ! SYSTEMATICS){
        
        
              const Int_t nVars = 3;
      Int_t vars[nVars] = {
//        AliReducedVarManager::kPeriod, 
        AliReducedVarManager::kINT7Triggered, 
        AliReducedVarManager::kVtxZmc,
        multEstimator }; 

      TArrayD eventHistBinLimits[nVars];
//      eventHistBinLimits[0] = TArrayD( kNperiodBins,                periodBins );
      eventHistBinLimits[0] = TArrayD( kNMBBins,                    mbBins );
      eventHistBinLimits[1] = TArrayD( kNVtxBins,                   vtxBins );
      eventHistBinLimits[2] = TArrayD( nMultBinLimitsNormalization, multBinLimitsNormalization );
    
      man->AddHistogram( classStr.Data(), "Normalization", "Normalization Histogram", nVars, vars, eventHistBinLimits /*, AliReducedVarManager::kOneOverEventEff */ );
      
      
      
        
        
              man->AddHistogram(classStr.Data(),"RunID_PhysSel","Run IDs vs trigger",kTRUE, 
                     nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                     2, 0., 2., AliReducedVarManager::kIsPhysicsSelection );
      
      
            
      
      man->AddHistogram(classStr.Data(),"RunID_AllEventCuts","Run IDs vs trigger",kTRUE, 
                     nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                     2, 0., 2., AliReducedVarManager::kAllEventCuts );
      
      
      man->AddHistogram(classStr.Data(),"RunID_TriggerEff","Run IDs vs trigger",kTRUE, 
                     nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                     2, 0., 2., AliReducedVarManager::kINT7Triggered );
      man->AddHistogram(classStr.Data(),"VtxZMC_TriggerEff","Run IDs vs trigger",kTRUE, 
                     40, -20., 20., AliReducedVarManager::kVtxZmc,
                     2, 0., 2., AliReducedVarManager::kINT7Triggered);
      
      
      man->AddHistogram(classStr.Data(),"VtxZMC_INELgt0","Run IDs vs trigger",kTRUE, 
                     40, -20., 20., AliReducedVarManager::kVtxZmc,
                     2, 0., 2., AliReducedVarManager::kINELgt0);
        
        
        
      man->AddHistogram(classStr.Data(),"RunID_MB","Run IDs vs trigger",kFALSE, 
                     nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                     2, 0., 2., AliReducedVarManager::kINT7Triggered );

      man->AddHistogram(classStr.Data(),"RunID_Period","Run IDs vs trigger",kFALSE, 
                     nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                     nPeriods, 0., nPeriods, AliReducedVarManager::kPeriod,0,0,0,-1, "", periods.Data()  );
      
      
      man->AddHistogram(classStr.Data(),"VtxX","Vtx X",kFALSE,300,0.,0.2,AliReducedVarManager::kVtxX);
      man->AddHistogram(classStr.Data(),"VtxY","Vtx Y",kFALSE,300,0.3,0.5,AliReducedVarManager::kVtxY);
      man->AddHistogram(classStr.Data(),"VtxZ","Vtx Z",kFALSE,300,-15.,15.,AliReducedVarManager::kVtxZ);
      man->AddHistogram(classStr.Data(),"VtxZmc","Vtx Zmc",kFALSE,300,-30.,30.,AliReducedVarManager::kVtxZmc);
      man->AddHistogram(classStr.Data(),"VtxZ_VtxZmc","Vtx Zmc",kFALSE,300,-15.,15.,AliReducedVarManager::kVtxZmc, 300, -15.,15.,AliReducedVarManager::kVtxZmc);
      
      man->AddHistogram(classStr.Data(), Form("RunNo_Vtx" ) ,"",kFALSE, 
        nRuns,0,nRuns,AliReducedVarManager::kRunID,
        40, -10., 10., AliReducedVarManager::kVtxZ);
      
      
      
      
      man->AddHistogram(classStr.Data(), Form("VZEROmult_Vtx" ) ,"",kFALSE, 
        1000,0.,2000.,AliReducedVarManager::kVZEROTotalMult,
        40, -10., 10., AliReducedVarManager::kVtxZ);
      
      
      
      man->AddHistogram(classStr.Data(), Form("VZEROAmult_VZEROCmult" ) ,"",kFALSE, 
        1000,0.,1000.,AliReducedVarManager::kVZEROATotalMult,
        1000,0.,1000.,AliReducedVarManager::kVZEROCTotalMult);
      
      man->AddHistogram(classStr.Data(), Form("VZEROmult_VZEROAmult" ) ,"",kFALSE, 
        1000,0.,1000.,AliReducedVarManager::kVZEROTotalMult,
        1000,0.,1000.,AliReducedVarManager::kVZEROATotalMult);
      
      
      man->AddHistogram(classStr.Data(), Form("VZEROmult_VZEROCmult" ) ,"",kFALSE, 
        1000,0.,1000.,AliReducedVarManager::kVZEROTotalMult,
        1000,0.,1000.,AliReducedVarManager::kVZEROCTotalMult);
      
      
      
      

      
      
//       for(Int_t ieta=0;ieta<32;++ieta) {
//         
//         int idx = AliReducedVarManager::AliReducedVarManager::kSPDntrackletsEtaBin+ieta;
//         int idx_corr = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kSPDntrackletsEtaBin+ieta,
//                                                                        AliReducedVarManager::kVertexCorr,
//                                                                        AliReducedVarManager::kMaximumMultiplicity  );
//         
//         int idx_corr_smear = AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kSPDntrackletsEtaBin+ieta, 
//                                                                              AliReducedVarManager::kVertexCorr, 
//                                                                              AliReducedVarManager::kMaximumMultiplicity,
//                                                                              AliReducedVarManager::kPoissonSmearing  
//                                                                            );
//         
//       man->AddHistogram(classStr.Data(), Form("RunNo_Vtx_TrackletsEta%d_prof", ieta ) ,"",kTRUE, 
//         nRuns,0,nRuns,AliReducedVarManager::kRunID,
//         80, -20., 20., AliReducedVarManager::kVtxZmc,
//                 200, 0.0, 200., idx, runNumbers.Data());
//      
//       }
      
      


      man->AddHistogram(classStr.Data(),"Vtx_VZEROAtotal_prof"  ,"",kTRUE, 
        80, -20., 20., AliReducedVarManager::kVtxZmc,
        2, 0., 2., AliReducedVarManager::kINT7Triggered, 
        200, 0.0, 200., iV0A);
        
      man->AddHistogram(classStr.Data(), "Vtx_VZEROCtotal_prof"  ,"",kTRUE, 
        80, -20., 20., AliReducedVarManager::kVtxZmc,
        2, 0., 2., AliReducedVarManager::kINT7Triggered, 
         200, 0.0, 200., iV0C);
      
      
      
      






      man->AddHistogram(classStr.Data(),"VZEROmult","",kFALSE, 2000, 0.0, 2000., iV0   );    
      

     man->AddHistogram(classStr.Data(),"VZEROmult_trigger","",kFALSE, 
      2000, 0.0, 2000., iV0 ,
      2, 0., 2., AliReducedVarManager::kINT7Triggered
  );    

      
      
      man->AddHistogram(classStr.Data(),"VZEROmultCorr","",kFALSE, 2000, 0.0, 2000., iV0GainLossMax   );    
      
      

      man->AddHistogram(classStr.Data(),"VZEROAmult","",kFALSE, 2000, 0.0, 2000., iV0A   );    
            
      man->AddHistogram(classStr.Data(),"VZEROAmultCorr","",kFALSE, 2000, 0.0, 2000., iV0AGainLossMax   );    
      
      

      man->AddHistogram(classStr.Data(),"VZEROCmult","",kFALSE, 2000, 0.0, 2000., iV0C   );    
            
      man->AddHistogram(classStr.Data(),"VZEROCmultCorr","",kFALSE, 2000, 0.0, 2000., iV0CGainLossMax   );    
            

      
      

      man->AddHistogram(classStr.Data(),"RunNo_Vtx_TrackletsOuterEta_prof","",kTRUE, 
        nRuns,0,nRuns,AliReducedVarManager::kRunID,
        80, -20., 20., AliReducedVarManager::kVtxZmc,
                200, 0.0, 200., AliReducedVarManager::kSPDntrackletsOuterEta, runNumbers.Data());

      man->AddHistogram(classStr.Data(),"RunNo_Vtx_Tracklets16_prof","",kTRUE, 
        nRuns,0,nRuns,AliReducedVarManager::kRunID,
        80, -20., 20., AliReducedVarManager::kVtxZmc,
                200, 0.0, 200., AliReducedVarManager::kSPDntracklets16, runNumbers.Data());
      
      
      

      man->AddHistogram(classStr.Data(),"RunNo_Vtx_Tracklets10_prof","",kTRUE, 
        nRuns,0,nRuns,AliReducedVarManager::kRunID,
        80, -20., 20., AliReducedVarManager::kVtxZmc,
                200, 0.0, 200., iTrk, runNumbers.Data());
      
      
      
      man->AddHistogram(classStr.Data(),"Vtx_Tracklets10","",kFALSE, 
        80, -20., 20., AliReducedVarManager::kVtxZmc,
                20, 0.0, 20., iTrk);
      man->AddHistogram(classStr.Data(),"Vtx_Nch10","",kFALSE, 
        80, -20., 20., AliReducedVarManager::kVtxZmc,
                20, 0.0, 20., AliReducedVarManager::kNch10);
      


      
      

      man->AddHistogram(classStr.Data(),"RunNo_Vtx_VZEROM_prof","",kTRUE, 
        nRuns,0,nRuns,AliReducedVarManager::kRunID,
        80, -20., 20., AliReducedVarManager::kVtxZmc,
                200, 0.0, 200., iV0, runNumbers.Data());
      
      

      man->AddHistogram(classStr.Data(),"RunNo_Vtx_VZEROA_prof","",kTRUE, 
        nRuns,0,nRuns,AliReducedVarManager::kRunID,
        80, -20., 20., AliReducedVarManager::kVtxZmc,
                200, 0.0, 200., iV0A, runNumbers.Data());
      
      

      man->AddHistogram(classStr.Data(),"RunNo_Vtx_VZEROC_prof","",kTRUE, 
        nRuns,0,nRuns,AliReducedVarManager::kRunID,
        80, -20., 20., AliReducedVarManager::kVtxZmc,
                200, 0.0, 200., iV0C, runNumbers.Data());
      

      man->AddHistogram(classStr.Data(),"RunNo_Vtx_VZEROAC_prof","",kTRUE, 
        nRuns,0,nRuns,AliReducedVarManager::kRunID,
        80, -20., 20., AliReducedVarManager::kVtxZmc,
                200, 0.0, 200., iV0AC, runNumbers.Data());

      

      
            man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMax_Nch10", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kFALSE,
                        200, -.5, 199.5, AliReducedVarManager::kNch10 ,
                        200, -.5, 199.5, iTrkCorrMax);
            
            man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMaxPoisson_Nch10", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kFALSE,
                        200, -.5, 199.5, AliReducedVarManager::kNch10 ,
                        200, -.5, 199.5, iTrkCorrMaxSmear);
      
            man->AddHistogram(classStr.Data(),"SPDntrackletsCorrAlpha_Nch10", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kFALSE,
                        200, -.5, 199.5, AliReducedVarManager::kNch10 ,
                        200, -.5, 199.5, AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kSPDntracklets, -2));
            
      
            man->AddHistogram(classStr.Data(),"VZEROalpha_NchV0", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kFALSE,
                        200, -.5, 199.5, AliReducedVarManager::kNchV0 ,
                        2000, -.5, 199.5, AliReducedVarManager::GetCorrectedMultiplicity( AliReducedVarManager::kVZEROTotalMult, -2));
            
      

      
            man->AddHistogram(classStr.Data(),"VZERO_NchV0", "", kFALSE,
                        200, -.5, 199.5, AliReducedVarManager::kNchV0 ,
                        2000, -.5, 1999.5, iV0);
            
            
            man->AddHistogram(classStr.Data(),"Nch10_NchV0", "", kFALSE,
                        200, -.5, 199.5, AliReducedVarManager::kNchV0 ,
                        200, -.5, 199.5, AliReducedVarManager::kNch10);
            
            
            man->AddHistogram(classStr.Data(),"VZEROAlpha_NchV0", "", kFALSE,
                        200, -.5, 199.5, AliReducedVarManager::kNchV0 ,
                        200, -.5, 199.5, AliReducedVarManager::GetCorrectedMultiplicity(  AliReducedVarManager::kVZEROTotalMult , -2 ));
            
            man->AddHistogram(classStr.Data(),"VZEROAlpha_Nch10", "", kFALSE,
                        200, -.5, 199.5, AliReducedVarManager::kNch10 ,
                        200, -.5, 199.5, AliReducedVarManager::GetCorrectedMultiplicity(  AliReducedVarManager::kVZEROTotalMult , -2 ));
            
            
            
      
      

      man->AddHistogram(classStr.Data(),"Vtx_Nch10_prof", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        200, 0., 200., AliReducedVarManager::kNch10  );

      
      
      
      
      man->AddHistogram(classStr.Data(),"SPDntracklets_Vtx_Nch10_rev", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        120, 0., 120., AliReducedVarManager::kNch10,
                        40, -20., 20., AliReducedVarManager::kVtxZmc,
                        120, 0., 120., iTrk);
      man->AddHistogram(classStr.Data(),"SPDntracklets_Vtx_Nch10", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        120, 0., 120., iTrk,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        120, 0., 120., AliReducedVarManager::kNch10);
      
      
      
      
      man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMax_Vtx_Nch10_rev", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        120, 0., 120., AliReducedVarManager::kNch10 ,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        120, 0., 120., iTrkCorrMax);
      man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMaxPoisson_Vtx_Nch10_rev", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        120, 0., 120., AliReducedVarManager::kNch10 ,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        120, 0., 120., iTrkCorrMaxSmear);
      

     man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMax_Vtx_Nch10", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        120, 0., 120., iTrkCorrMax,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        120, 0., 120., AliReducedVarManager::kNch10 );
     man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMaxPoisson_Vtx_Nch10", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        120, 0., 120., iTrkCorrMaxSmear,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        120, 0., 120., AliReducedVarManager::kNch10 );
      
      
      
      
      man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMin_Vtx_Nch10_rev", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        120, 0., 120., AliReducedVarManager::kNch10 ,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        120, 0., 120., iTrkCorrMin);
      man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMinPoisson_Vtx_Nch10_rev", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        120, 0., 120., AliReducedVarManager::kNch10 ,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        120, 0., 120., iTrkCorrMinSmear);
      

     man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMin_Vtx_Nch10", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        120, 0., 120., iTrkCorrMin,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        120, 0., 120., AliReducedVarManager::kNch10 );
     man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMinPoisson_Vtx_Nch10", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        120, 0., 120., iTrkCorrMinSmear,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        120, 0., 120., AliReducedVarManager::kNch10 );
      
      
      
      
      man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMean_Vtx_Nch10_rev", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        120, 0., 120., AliReducedVarManager::kNch10 ,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        120, 0., 120., iTrkCorrMean);
      man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMeanPoisson_Vtx_Nch10_rev", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        120, 0., 120., AliReducedVarManager::kNch10 ,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        120, 0., 120., iTrkCorrMeanSmear);
      

     man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMean_Vtx_Nch10", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        120, 0., 120., iTrkCorrMean,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        120, 0., 120., AliReducedVarManager::kNch10 );
     man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMeanPoisson_Vtx_Nch10", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        120, 0., 120., iTrkCorrMeanSmear,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        120, 0., 120., AliReducedVarManager::kNch10 );
     
      
      man->AddHistogram(classStr.Data(),"V0AMult_NchV0", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kFALSE,
                        200, 0., 100000., iV0A,
                        200, 0., 20000., AliReducedVarManager::kNchV0A );
     
      
      man->AddHistogram(classStr.Data(),"V0CMult_NchV0", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kFALSE,
                        200, 0., 100000., iV0C,
                        200, 0., 20000., AliReducedVarManager::kNchV0C );
     
      
      man->AddHistogram(classStr.Data(),"V0Mult_NchV0", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kFALSE,
                        200, 0., 100000., iV0,
                        200, 0., 20000., AliReducedVarManager::kNchV0 );
     
     
      
      man->AddHistogram(classStr.Data(),"SPDntracklets_Nch10", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kFALSE,
                        200, 0., 200., iTrk,
                        200, 0., 200., AliReducedVarManager::kNch10 );
      
      man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMax_VtxEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20., iTrkCorrMax,
                        201, -1., 200., AliReducedVarManager::kHasVtx );
      
      man->AddHistogram(classStr.Data(),"ZVtxMC_VtxEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        201, -1., 200., AliReducedVarManager::kHasVtx );
      
      man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMax_ZVtxMC_VtxEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20., iTrkCorrMax,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        201, -1., 200., AliReducedVarManager::kHasVtx );
      
      
      man->AddHistogram(classStr.Data(),"V0or", "", kFALSE,
                        1000, 0., 1., AliReducedVarManager::kV0or);
      
      
      man->AddHistogram(classStr.Data(),"Nch16_TriggerEff", "", kTRUE,
                        20, 0., 20., AliReducedVarManager::kNch16,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      man->AddHistogram(classStr.Data(),"onebin_TriggerEff", "", kTRUE,
                        1, 0., 2000., AliReducedVarManager::kNch16,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      man->AddHistogram(classStr.Data(),"onebin_PhysSel", "", kTRUE,
                        1, 0., 2000., AliReducedVarManager::kNch16,
                        201, -1., 200., AliReducedVarManager::kIsPhysicsSelection );
      
      
      man->AddHistogram(classStr.Data(),"Triggered_PhysSel", "", kFALSE,
                        2, 0., 2., AliReducedVarManager::kINT7Triggered,
                        2, 0., 2, AliReducedVarManager::kIsPhysicsSelection );
      
      man->AddHistogram(classStr.Data(),"Nch16_VtxEff", "", kTRUE,
                        20, 0., 20., AliReducedVarManager::kNch16,
                        201, -1., 200., AliReducedVarManager::kHasVtx );
      
//       man->AddHistogram(classStr.Data(),"Nch10_TriggerEff", "", kTRUE,
//                         20, 0., 20., AliReducedVarManager::kNch10,
//                         201, -1., 200., AliReducedVarManager::kINT7Triggered );
//       
//       
//       
//       man->AddHistogram(classStr.Data(),"Nch16JpsiExcl_TriggerEff", "", kTRUE,
//                         20, 0., 20., AliReducedVarManager::kNch16JpsiExcl,
//                         201, -1., 200., AliReducedVarManager::kINT7Triggered );
//       
//       man->AddHistogram(classStr.Data(),"Nch10JpsiExcl_TriggerEff", "", kTRUE,
//                         20, 0., 20., AliReducedVarManager::kNch10JpsiExcl,
//                         201, -1., 200., AliReducedVarManager::kINT7Triggered );
//       
//       
//       
//       
/*      
      man->AddHistogram(classStr.Data(),"Nch16JpsiExcl_Nch16", "", kFALSE,
                        100, 0., 100., AliReducedVarManager::kNch16JpsiExcl,
                        100, 0., 100., AliReducedVarManager::kNch16 );
      
      man->AddHistogram(classStr.Data(),"Nch10JpsiExcl_Nch10", "", kFALSE,
                        100, 0., 100., AliReducedVarManager::kNch10JpsiExcl,
                        100, 0., 100., AliReducedVarManager::kNch10 );
      
      
      */
      
//       man->AddHistogram(classStr.Data(),"NchV0_TriggerEff", "", kTRUE,
//                         20, 0., 20., AliReducedVarManager::kNchV0,
//                         201, -1., 200., AliReducedVarManager::kINT7Triggered );
//       
//       man->AddHistogram(classStr.Data(),"NchV0or_TriggerEff", "", kTRUE,
//                         20, 0., 20., AliReducedVarManager::kNchV0or,
//                         201, -1., 200., AliReducedVarManager::kINT7Triggered );
//       
//       
//       
//       
      
      
            
      
      man->AddHistogram(classStr.Data(),"Vtx_Trk16_TriggerEff", "", kTRUE,
                        200, -10., 10., AliReducedVarManager::kVtxZmc,
                        20,0., 20., AliReducedVarManager::kSPDntracklets16,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      
      man->AddHistogram(classStr.Data(),"Vtx_Trk16_VertexEff", "", kTRUE,
                        200, -10., 10., AliReducedVarManager::kVtxZmc,
                        20,0., 20., AliReducedVarManager::kSPDntracklets16,
                        201, -1., 200., AliReducedVarManager::kHasVtx );
      
      
      man->AddHistogram(classStr.Data(),"Vtx_Trk10_VertexEff", "", kTRUE,
                        200, -10., 10., AliReducedVarManager::kVtxZmc,
                        20,0., 20., AliReducedVarManager::kSPDntracklets,
                        201, -1., 200., AliReducedVarManager::kHasVtx );
      
      
      man->AddHistogram(classStr.Data(),"Vtx_Trk10Corr_VertexEff", "", kTRUE,
                        200, -10., 10., AliReducedVarManager::kVtxZmc,
                        20,0., 20., iTrkCorrMaxSmear,
                        201, -1., 200., AliReducedVarManager::kHasVtx );
      
      
      man->AddHistogram(classStr.Data(),"Trk10_Trk16", "", kFALSE,
                        200, 0., 20., AliReducedVarManager::kSPDntracklets,
                        20,0., 20., AliReducedVarManager::kSPDntracklets16 );
      
      man->AddHistogram(classStr.Data(),"V0or_Trk16", "", kFALSE,
                        200, 0., 20., AliReducedVarManager::kV0or,
                        20,0., 20., AliReducedVarManager::kSPDntracklets16);
      
      man->AddHistogram(classStr.Data(),"V0or_Trk16_TriggerEff", "", kTRUE,
                        200, 0., 20., AliReducedVarManager::kV0or,
                        20,0., 20., AliReducedVarManager::kSPDntracklets16,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      
      man->AddHistogram(classStr.Data(),"V0or_Trk16_VertexEff", "", kTRUE,
                        200, 0., 20., AliReducedVarManager::kV0or,
                        20,0., 20., AliReducedVarManager::kSPDntracklets16,
                        201, -1., 200., AliReducedVarManager::kHasVtx );
      
      man->AddHistogram(classStr.Data(),"Trk10_Trk16_VertexEff", "", kTRUE,
                        200, 0., 20., AliReducedVarManager::kSPDntracklets,
                        20,0., 20., AliReducedVarManager::kSPDntracklets16,
                        201, -1., 200., AliReducedVarManager::kHasVtx );
      
      man->AddHistogram(classStr.Data(),"Trk08_Trk16_VertexEff", "", kTRUE,
                        200, 0., 20., AliReducedVarManager::kSPDntracklets08,
                        20,0., 20., AliReducedVarManager::kSPDntracklets16,
                        201, -1., 200., AliReducedVarManager::kHasVtx );
      
      man->AddHistogram(classStr.Data(),"Trk08_Trk10_VertexEff", "", kTRUE,
                        200, 0., 20., AliReducedVarManager::kSPDntracklets08,
                        20,0., 20., AliReducedVarManager::kSPDntracklets,
                        201, -1., 200., AliReducedVarManager::kHasVtx );
      
      
      man->AddHistogram(classStr.Data(),"V0or_TriggerEff_coarse", "", kTRUE,
                        3, 0., 15., AliReducedVarManager::kV0or,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      
      man->AddHistogram(classStr.Data(),"V0or_TriggerEff", "", kTRUE,
                        75, 0., 15., AliReducedVarManager::kV0or,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      man->AddHistogram(classStr.Data(),"V0or_INELgt0", "", kTRUE,
                        10, 0., 10., AliReducedVarManager::kV0or,
                        201, -1., 200., AliReducedVarManager::kINELgt0 );
      /*
      man->AddHistogram(classStr.Data(),"NchMidOrV0_TriggerEff", "", kTRUE,
                        20, 0., 20., AliReducedVarManager::kNchMidOrV0,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      

      
      
      man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMax_TriggerEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20., iTrkCorrMax,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      man->AddHistogram(classStr.Data(),"ZVtxMC_TriggerEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMax_ZVtxMC_TriggerEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20., iTrkCorrMax,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );*/
      
      
      
            man->AddHistogram(classStr.Data(),"V0M_TriggerEff", "", kTRUE,
                        100, 0., 100., iV0,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );   
            
            man->AddHistogram(classStr.Data(),"SPDntracklets_TriggerEff", "", kTRUE,
                        20, 0., 20., iTrkCorrMax,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );      
      
            
            man->AddHistogram(classStr.Data(),"V0M_VertexEff", "", kTRUE,
                       100, 0., 100., iV0,
                        201, -1., 200., AliReducedVarManager::kHasVtx );   
            man->AddHistogram(classStr.Data(),"SPDntracklets_VertexEff", "", kTRUE,
                        20, 0., 20., iTrkCorrMax,
                        201, -1., 200., AliReducedVarManager::kHasVtx );  
      
            
            man->AddHistogram(classStr.Data(),"V0M_Vertexlt10Eff", "", kTRUE,
                       100, 0., 100., iV0,
                        201, -1., 200., AliReducedVarManager::kVtxZlt10 );   
            man->AddHistogram(classStr.Data(),"SPDntracklets_Vertexlt10Eff", "", kTRUE,
                        20, 0., 20., iTrkCorrMax,
                        201, -1., 200., AliReducedVarManager::kVtxZlt10 );
            
            
            man->AddHistogram(classStr.Data(),"V0M_INELgt0", "", kTRUE,
                       100, 0., 100., iV0,
                        201, -1., 200., AliReducedVarManager::kINELgt0 );   
            man->AddHistogram(classStr.Data(),"SPDntracklets_INELgt0", "", kTRUE,
                        20, 0., 20., iTrkCorrMax,
                        201, -1., 200., AliReducedVarManager::kINELgt0 );
            
            
            man->AddHistogram(classStr.Data(),"V0M_all", "", kTRUE,
                       100, 0., 100., iV0,
                        201, -1., 200., AliReducedVarManager::kAllEventCuts );   
            man->AddHistogram(classStr.Data(),"SPDntracklets_all", "", kTRUE,
                        20, 0., 20., iTrkCorrMax,
                        201, -1., 200., AliReducedVarManager::kAllEventCuts );
            
            
            man->AddHistogram(classStr.Data(),"onBin_all", "", kTRUE,
                       1, 0., 100., AliReducedVarManager::kINT7Triggered,
                        201, -1., 200., AliReducedVarManager::kAllEventCuts );   
            
            
            
            
            man->AddHistogram(classStr.Data(),"V0M_Vertexlt10Eff_wider", "", kTRUE,
                       600, 0., 600., iV0,
                        201, -1., 200., AliReducedVarManager::kVtxZlt10 );   
            man->AddHistogram(classStr.Data(),"SPDntracklets_Vertexlt10Eff_wieder", "", kTRUE,
                        100, 0., 100., iTrkCorrMax,
                        201, -1., 200., AliReducedVarManager::kVtxZlt10 );
            
            man->AddHistogram(classStr.Data(),"Nch10_Vertexlt10Eff_wieder", "", kTRUE,
                        100, 0., 100., AliReducedVarManager::kNch10,
                        201, -1., 200., AliReducedVarManager::kVtxZlt10 );
            
            
            
            
            
            man->AddHistogram(classStr.Data(),"SPDntrackletsouterEta_Vertexlt10Eff_wieder", "", kTRUE,
                        100, 0., 100., AliReducedVarManager::kSPDntrackletsOuterEta,
                        201, -1., 200., AliReducedVarManager::kVtxZlt10 );
            man->AddHistogram(classStr.Data(),"SPDntrackletsCorr_Vertexlt10Eff_wieder", "", kTRUE,
                        100, 0., 100., iTrkCorrMax,
                        201, -1., 200., AliReducedVarManager::kVtxZlt10 );
            
            
            man->AddHistogram(classStr.Data(),"SPDntrackletsOuterEta_INELgt0", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20., AliReducedVarManager::kSPDntrackletsOuterEta,
                        201, -1., 200., AliReducedVarManager::kINELgt0 );
            
            
            man->AddHistogram(classStr.Data(),"SPDntrackletsOuterEta_INELgt0vtx", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20., AliReducedVarManager::kSPDntrackletsOuterEta,
                        201, -1., 200., AliReducedVarManager::kTriggeredVtxINELgt0 );
            
            
            man->AddHistogram(classStr.Data(),"SPDntrackletsOuterEta_Vtx_INELgt0", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20., AliReducedVarManager::kSPDntrackletsOuterEta,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        201, -1., 200., AliReducedVarManager::kINELgt0 );
            
            
            
            man->AddHistogram(classStr.Data(),"SPDntrackletsOuterEta_VertexEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20., AliReducedVarManager::kSPDntrackletsOuterEta,
                        201, -1., 200., AliReducedVarManager::kHasVtx );
            
            man->AddHistogram(classStr.Data(),"SPDntrackletsOuterEta_innerEta_VertexEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20., AliReducedVarManager::kSPDntrackletsOuterEta,
                        20, 0., 20., AliReducedVarManager::kSPDntracklets,
                        201, -1., 200., AliReducedVarManager::kHasVtx );
            
            man->AddHistogram(classStr.Data(),"SPDntrackletsOuterEta_innerEta", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kFALSE,
                        100, 0., 100., AliReducedVarManager::kSPDntrackletsOuterEta,
                        100, 0., 100., AliReducedVarManager::kSPDntracklets);
            
            
            
            man->AddHistogram(classStr.Data(),"SPDntracklets16_INELgt0", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20., AliReducedVarManager::kSPDntracklets16,
                        201, -1., 200., AliReducedVarManager::kINELgt0 );
      
      man->AddHistogram(classStr.Data(),"NchV0A_NchV0C_triggerEff","",kTRUE, 
                100, 0.0, 100., AliReducedVarManager::kNchV0A, 
                100, 0.0, 100., AliReducedVarManager::kNchV0C, 
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      
      
      
      

      

      man->AddHistogram(classStr.Data(),"VZEROA_VZEROC_triggerEff","",kTRUE, 
                150, 0.0, 15., iV0A, 
                140, 0.0, 15., iV0C,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      
      
      
      man->AddHistogram(classStr.Data(),"SPDntracklets", "SPD #tracklets in |#eta|<1.0", kFALSE,
                        201, -1., 200., iTrk    );
      man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMax", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kFALSE,
                        201, -1., 200., iTrkCorrMax );
      man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMaxSmear", "corrected SPD #tracklets in |#eta|<1.0 (max mult, Poisson)", kFALSE, 
                        201, -1., 200., iTrkCorrMaxSmear );
      
      
      man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMaxvs_Poisson", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kFALSE,
                        201, -1., 200., iTrkCorrMax,
                        201, -1., 200., iTrkCorrMaxSmear );
      
      
      
      man->AddHistogram(classStr.Data(),"SPDntracklets_VTX", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                         200,-10.,10.,AliReducedVarManager::kVtxZmc, 2, 0., 2., AliReducedVarManager::kINT7Triggered, 
                        201, -1., 200., iTrk  );
      man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMax_VTX", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE, 
                         200,-10.,10.,AliReducedVarManager::kVtxZmc, 2, 0., 2., AliReducedVarManager::kINT7Triggered, 
                        201, -1., 200., iTrkCorrMax );
      man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMaxSmear_VTX", "corrected SPD #tracklets in |#eta|<1.0 (max mult, Poisson)", kTRUE, 
                         200,-10.,10.,AliReducedVarManager::kVtxZmc, 2, 0., 2., AliReducedVarManager::kINT7Triggered,
                        201, -1., 200., iTrkCorrMaxSmear );

      
      
//       for(Int_t il=0; il<2; ++il){
//         man->AddHistogram(classStr.Data(), Form("SPDfiredChips_layer%d",il+1), Form("SPD fired chips in layer %d",il+1), 
//               kFALSE, 300, 0., 300., AliReducedVarManager::kSPDFiredChips+il);
//         man->AddHistogram(classStr.Data(), Form("SPDfiredChips_layer%d_Vtx",il+1), Form("SPD fired chips in layer %d",il+1), 
//               kTRUE, 
//               200,-10.,10.,AliReducedVarManager::kVtxZmc, 
//               2, 0., 2., AliReducedVarManager::kINT7Triggered, 
//               300, 0., 300., AliReducedVarManager::kSPDFiredChips+il);
//         
//         
//         
//         
//         
//       }
//         
//         man->AddHistogram(classStr.Data(), Form("SPDfiredChips_layer1_2",il+1), Form("SPD fired chips in layer %d",il+1), 
//               kFALSE,
//               200, 0., 1000., AliReducedVarManager::kSPDFiredChips,
//               200, 0., 1000., AliReducedVarManager::kSPDFiredChips+1);
//         
//         
//         
// 
//       
//         
//         man->AddHistogram(classStr.Data(), "SPDnSingleClusters", "SPD single clusters", 
//             kFALSE, 500, 0., 500., AliReducedVarManager::kSPDnSingleClusters);  
//       
//       
// 
//       man->AddHistogram(classStr.Data(),"VZEROAmult_tracklets_corr", "", kFALSE, 
//           100, 0.0, 1000., iV0AGainLossMax, 
//           200, 0.0, 200., iTrkCorrMax);
// 
//       man->AddHistogram(classStr.Data(),"VZEROMmult_tracklets_corr", "", kFALSE, 
//           200, 0.0,2000., iV0GainLossMax, 
//           200, 0.0, 200., iTrkCorrMax);
//       
// 
//       man->AddHistogram(classStr.Data(),"VZEROCmult_tracklets_corr", "", kFALSE, 
//           100, 0.0, 1000., iV0CGainLossMax, 
//           200, 0.0, 200., iTrkCorrMax);
//       
//       man->AddHistogram(classStr.Data(),"VZEROAplusCmult_tracklets_corr", "", kFALSE, 
//           100, 0.0, 1000., iV0ACGainLossMax, 
//           200, 0.0, 200., iTrkCorrMax);
//       
//       
// 
//       man->AddHistogram(classStr.Data(),"VZEROMmult_tracklets_uncorr", "", kFALSE, 
//           200, 0.0, 2000., iV0, 
//           200, 0.0, 200., iTrk);
//       man->AddHistogram(classStr.Data(),"VZEROAmult_tracklets_uncorr", "", kFALSE, 
//           100, 0.0, 1000., iV0A, 
//           200, 0.0, 200., iTrk);
//       
// 
//       man->AddHistogram(classStr.Data(),"VZEROCmult_tracklets_uncorr", "", kFALSE, 
//           100, 0.0, 1000., iV0C, 
//           200, 0.0, 200., iTrk);
//       
//       
//    man->AddHistogram(classStr.Data(),"clusters_tracklets", "", kFALSE,
//                      200, 0.0, 200.,  AliReducedVarManager::kMultEstimatorSPDTracklets,
//                      200, 0.0, 1000.,  AliReducedVarManager::kMultEstimatorSPDClusters);
//    
//    man->AddHistogram(classStr.Data(),"clusters_v0m", "", kFALSE,
//                      200, 0.0, 15000.,  AliReducedVarManager::kMultEstimatorOnlineV0M,
//                      400, 0.0, 800.,  AliReducedVarManager::kMultEstimatorSPDClusters);
//    
//    
//    
//    
//    
//    man->AddHistogram(classStr.Data(),"tracklets_v0m", "", kFALSE,
//                      200, 0.0, 15000.,  AliReducedVarManager::kMultEstimatorOnlineV0M,
//                      200, 0.0, 200.,  AliReducedVarManager::kMultEstimatorSPDTracklets);
//    
//    
   
   

      
//       man->AddHistogram(classStr.Data(),"IsPhysicsSelection","Physics selection flag",kFALSE,
//                         2,-0.5,1.5,AliReducedVarManager::kIsPhysicsSelection, 0,0.0,0.0,AliReducedVarManager::kNothing,
//                         0,0.0,0.0,AliReducedVarManager::kNothing, "off;on");
// 
//             man->AddHistogram(classStr.Data(),"TZEROpileup","SPD pileup flag",kFALSE,
//                         2,-0.5,1.5,AliReducedVarManager::kTZEROpileup, 0,0.0,0.0,AliReducedVarManager::kNothing,
//                         0,0.0,0.0,AliReducedVarManager::kNothing, "off;on");
//             
//             
//             man->AddHistogram(classStr.Data(),"TZEROsatellite","SPD pileup flag",kFALSE,
//                         2,-0.5,1.5,AliReducedVarManager::kTZEROsatellite, 0,0.0,0.0,AliReducedVarManager::kNothing,
//                         0,0.0,0.0,AliReducedVarManager::kNothing, "off;on");
//             
//             
//             man->AddHistogram(classStr.Data(),"IsSPDpileup","SPD pileup flag",kFALSE,
//                         2,-0.5,1.5,AliReducedVarManager::kIsSPDPileup, 0,0.0,0.0,AliReducedVarManager::kNothing,
//                         0,0.0,0.0,AliReducedVarManager::kNothing, "off;on");  
//             
//             man->AddHistogram(classStr.Data(),"IsMVpileup","SPD pileup flag",kFALSE,
//                         2,-0.5,1.5,AliReducedVarManager::kIsPileupMV, 0,0.0,0.0,AliReducedVarManager::kNothing,
//                         0,0.0,0.0,AliReducedVarManager::kNothing, "off;on");           
//             
//             
//             
//             man->AddHistogram(classStr.Data(),"IsSPDpileupMultBins","SPD pileup flag (mult bins)",kFALSE,
//                         2,-0.5,1.5,AliReducedVarManager::kIsSPDPileupMultBins, 0,0.0,0.0,AliReducedVarManager::kNothing,
//                         0,0.0,0.0,AliReducedVarManager::kNothing, "off;on");
//             
//             
//             man->AddHistogram(classStr.Data(),"IsSPDpileup5","SPD pileup flag",kFALSE,
//                         2,-0.5,1.5,AliReducedVarManager::kIsSPDPileup5, 0,0.0,0.0,AliReducedVarManager::kNothing,
//                         0,0.0,0.0,AliReducedVarManager::kNothing, "off;on");
//             

            
            
            
      man->AddHistogram(classStr.Data(),"TPCITS","",kFALSE,
                        100, 0.0, 100., AliReducedVarManager::kNTracksTPCoutVsITSout);
      
      
      
      
      
            
            
      man->AddHistogram(classStr.Data(),"TPCout","",kFALSE,
                        1000, 0.0, 10000., AliReducedVarManager::kNTracksPerTrackingStatus + AliReducedVarManager::kTPCout);
      
      man->AddHistogram(classStr.Data(),"TPCin","",kFALSE,
                        1000, 0.0, 10000., AliReducedVarManager::kNTracksPerTrackingStatus + AliReducedVarManager::kTPCin);
            
            
      man->AddHistogram(classStr.Data(),"TOFout","",kFALSE,
                        100, 0.0, 100., AliReducedVarManager::kNTracksPerTrackingStatus + AliReducedVarManager::kTOFout);
            
            
      man->AddHistogram(classStr.Data(),"TPCout_TPCin","",kFALSE,
                        200, 0.0, 2000., AliReducedVarManager::kNTracksPerTrackingStatus + AliReducedVarManager::kTPCout,
                        1000, 0.0, 10000., AliReducedVarManager::kNTracksPerTrackingStatus + AliReducedVarManager::kTPCin);
            
      man->AddHistogram(classStr.Data(),"TPCout_VZERO","",kFALSE,
                        200, 0.0, 2000., AliReducedVarManager::kNTracksPerTrackingStatus + AliReducedVarManager::kTPCout,
                        300, 0.0, 1500., iV0);
            
      man->AddHistogram(classStr.Data(),"TPCout_VZEROcorr","",kFALSE,
                        200, 0.0, 2000., AliReducedVarManager::kNTracksPerTrackingStatus + AliReducedVarManager::kTPCout,
                        300, 0.0, 1500., iV0GainLossMax);
      
      

            
      
      man->AddHistogram(classStr.Data(),"tpcOut_VZEROcorr_pairs","",kTRUE,
                        20, 0.0, 2000., AliReducedVarManager::kNTracksPerTrackingStatus + AliReducedVarManager::kTPCout,
                        30, 0.0, 1200., iV0GainLossMax,
                        100, 0., 100., AliReducedVarManager::kNpairsSelected                        
                       );
      
      man->AddHistogram(classStr.Data(),"tpcOut_VZEROcorr_tracks","",kTRUE,
                        20, 0.0, 2000., AliReducedVarManager::kNTracksPerTrackingStatus + AliReducedVarManager::kTPCout,
                        30, 0.0, 1200., iV0GainLossMax,
                        100, 0., 100., AliReducedVarManager::kNtracksAnalyzed                        
                       );
      
      man->AddHistogram(classStr.Data(),"tpcOut_trk_pairs","",kTRUE,
                        20, 0.0, 2000., AliReducedVarManager::kNTracksPerTrackingStatus + AliReducedVarManager::kTPCout,
                        30, 0.0, 120., iTrkCorrMax,
                        100, 0., 100., AliReducedVarManager::kNpairsSelected                        
                       );
      
      man->AddHistogram(classStr.Data(),"tpcOut_trk_tracks","",kTRUE,
                        20, 0.0, 2000., AliReducedVarManager::kNTracksPerTrackingStatus + AliReducedVarManager::kTPCout,
                        30, 0.0, 120., iTrkCorrMax,
                        100, 0., 100., AliReducedVarManager::kNtracksAnalyzed                        
                       );
      
      

      
      
      man->AddHistogram(classStr.Data(),"Trk_VZEROcorr_pileup","",kTRUE,
                        20, 0.0, 100., iTrkCorrMax,
                        30, 0.0, 1200., iV0GainLossMax,
                        100, 0., 100., AliReducedVarManager::kIsSPDPileup                        
                       );
      
      
      man->AddHistogram(classStr.Data(),"TPCout_Tracklets","",kFALSE,
                        200, 0.0, 2000., AliReducedVarManager::kNTracksPerTrackingStatus + AliReducedVarManager::kTPCout,
                        200, 0.0, 200., iTrkCorrMax);
            
      man->AddHistogram(classStr.Data(),"TOFout_Tracklets","",kFALSE,
                        120, 0.0, 120., AliReducedVarManager::kNTracksPerTrackingStatus + AliReducedVarManager::kTOFout,
                        200, 0.0, 200., iTrkCorrMax);
      
      man->AddHistogram(classStr.Data(),"TOFout_V0","",kFALSE,
                        120, 0.0, 120., AliReducedVarManager::kNTracksPerTrackingStatus + AliReducedVarManager::kTOFout,
                        1200, 0.0, 1200., iV0GainLossMax);
      

   man->AddHistogram(classStr.Data(),"TOFout_V0_T0pileup","",kTRUE,
                        120, 0.0, 120., AliReducedVarManager::kNTracksPerTrackingStatus + AliReducedVarManager::kTOFout,
                        1200, 0.0, 1200., iV0GainLossMax
			,2, -0.5, 1.5,  AliReducedVarManager::kTZEROpileup   );
      
      
      man->AddHistogram(classStr.Data(),"v0m_triggerTPCITS_2D","",kFALSE,
                        300, 0.0, 1500., iV0,
                        100, 0.0, 200., AliReducedVarManager::kNTracksTPCoutVsITSout);
      
      
      
      
      man->AddHistogram(classStr.Data(),"v0m_triggerTPCITS","",kTRUE,
                        300, 0.0, 1500., iV0,
                        2,-.5 , 1.5, AliReducedVarManager::kINT7Triggered, 
                        100, -10.0, 10., AliReducedVarManager::kNTracksTPCoutVsITSout);
            
            
      man->AddHistogram(classStr.Data(),"TOFITS","",kFALSE,
                        100, 0.0, 100., AliReducedVarManager::kNTracksTOFoutVsITSout);
      
      
      
      man->AddHistogram(classStr.Data(),"v0m_triggerTOFITS","",kTRUE,
                        300, 0.0, 1500., iV0,
                        2,-.5 , 1.5, AliReducedVarManager::kINT7Triggered, 
                        100, -10.0, 10., AliReducedVarManager::kNTracksTOFoutVsITSout);
      
      
            
      man->AddHistogram(classStr.Data(),"deltaVtx","",kFALSE,
                        100, -10.0, 10., AliReducedVarManager::kDeltaVtxZ);
      
      
            man->AddHistogram(classStr.Data(),"deltaVtxSPD","",kFALSE,
                        100, -10.0, 10.,     AliReducedVarManager::kDeltaVtxZspd);
            
            
            
            
      man->AddHistogram(classStr.Data(),"v0m_triggerdeltaVtx","",kTRUE,
                        300, 0.0, 1500., iV0,
                        2,-.5 , 1.5, AliReducedVarManager::kINT7Triggered, 
                        100, -10.0, 10., AliReducedVarManager::kDeltaVtxZ);
      
      
            man->AddHistogram(classStr.Data(),"v0m_triggerdeltaVtxSPD","",kTRUE,
                        300, 0.0, 1500., iV0,
                        2,-.5 , 1.5, AliReducedVarManager::kINT7Triggered, 
                        100, -10.0, 10.,     AliReducedVarManager::kDeltaVtxZspd);
            
   
      
      man->AddHistogram(classStr.Data(),"IsPileupMV_v0m_Trigger","",kTRUE,
                        300, 0.0, 1500., iV0,
                        2,-.5 , 1.5, AliReducedVarManager::kINT7Triggered, 
                        2,-0.5,1.5,AliReducedVarManager::kIsPileupMV);
      
      man->AddHistogram(classStr.Data(),"IsT0pileup_v0m_Trigger","",kTRUE,
                        300, 0.0, 1500., iV0,
                        2,-.5 , 1.5, AliReducedVarManager::kINT7Triggered, 
                        2,-0.5,1.5,AliReducedVarManager::kTZEROpileup);
      
      man->AddHistogram(classStr.Data(),"IsT0sattelite_v0m_Trigger","",kTRUE,
                        300, 0.0, 1500., iV0,
                        2,-.5 , 1.5, AliReducedVarManager::kINT7Triggered, 
                        2,-0.5,1.5,AliReducedVarManager::kTZEROsatellite);
   
   
      
      man->AddHistogram(classStr.Data(),"IsSPDpileup_v0m_Trigger","",kTRUE,
                        300, 0.0, 1500., iV0,
                        2,-.5 , 1.5, AliReducedVarManager::kINT7Triggered, 
                        2,-0.5,1.5,AliReducedVarManager::kIsSPDPileup);
      
      man->AddHistogram(classStr.Data(),"IsSPDpileup5_v0m_Trigger","",kTRUE,
                        300, 0.0, 1500., iV0,
                        2,-.5 , 1.5, AliReducedVarManager::kINT7Triggered, 
                        2,-0.5,1.5,AliReducedVarManager::kIsSPDPileup5);
      
      
      
      
      
            man->AddHistogram(classStr.Data(),"RunNo_SPDpileUpProfile","",kTRUE, nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                            2,0,2,AliReducedVarManager::kINT7Triggered,
                                                        100, 0.0, 100., AliReducedVarManager::kIsSPDPileup,runNumbers.Data());
      
      man->AddHistogram(classStr.Data(),"RunNo_SPDpileUpMultBinsProfile","",kTRUE, nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                            2,0,2,AliReducedVarManager::kINT7Triggered,
                                                        100, 0.0, 100., AliReducedVarManager::kIsSPDPileupMultBins,runNumbers.Data());
      
      man->AddHistogram(classStr.Data(),"RunNo_MVPileUpProfile","",kTRUE, nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                            2,0,2,AliReducedVarManager::kINT7Triggered,
                                                        100, 0.0, 100., AliReducedVarManager::kIsPileupMV,runNumbers.Data());


      man->AddHistogram(classStr.Data(),"RunNo_T0PileUpProfile","",kTRUE, nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                            2,0,2,AliReducedVarManager::kINT7Triggered,
                                                        100, 0.0, 100., AliReducedVarManager::kTZEROpileup,runNumbers.Data());

      man->AddHistogram(classStr.Data(),"RunNo_T0SatteliteProfile","",kTRUE, nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                            2,0,2,AliReducedVarManager::kINT7Triggered,
                                                        100, 0.0, 100., AliReducedVarManager::kTZEROsatellite,runNumbers.Data());
      
      
      
      
      
   
      
      man->AddHistogram(classStr.Data(),"IsPileupMV_v0mCorr_Trigger","",kTRUE,
                        300, 0.0, 1500., iV0GainLossMax,
                        2,-.5 , 1.5, AliReducedVarManager::kINT7Triggered, 
                        2,-0.5,1.5,AliReducedVarManager::kIsPileupMV);
      
      man->AddHistogram(classStr.Data(),"IsT0pileup_v0mCorr_Trigger","",kTRUE,
                        300, 0.0, 1500., iV0GainLossMax,
                        2,-.5 , 1.5, AliReducedVarManager::kINT7Triggered, 
                        2,-0.5,1.5,AliReducedVarManager::kTZEROpileup);
      
      man->AddHistogram(classStr.Data(),"IsT0sattelite_v0mCorr_Trigger","",kTRUE,
                        300, 0.0, 1500., iV0GainLossMax,
                        2,-.5 , 1.5, AliReducedVarManager::kINT7Triggered, 
                        2,-0.5,1.5,AliReducedVarManager::kTZEROsatellite);
   
   
      
      man->AddHistogram(classStr.Data(),"IsSPDpileup_v0mCorr_Trigger","",kTRUE,
                        300, 0.0, 1500., iV0GainLossMax,
                        2,-.5 , 1.5, AliReducedVarManager::kINT7Triggered, 
                        2,-0.5,1.5,AliReducedVarManager::kIsSPDPileup);
   
      
      man->AddHistogram(classStr.Data(),"IsSPDpileup_SPDtracklets_V0","",kTRUE,
                        200, 0.0, 200., iTrk,
                         200, 0.0, 2000., iV0,
                        2,-0.5,1.5,AliReducedVarManager::kIsSPDPileup);
      
      man->AddHistogram(classStr.Data(),"IsPileupMB_SPDtracklets_V0","",kTRUE,
                        200, 0.0, 200., iTrk,
                         200, 0.0, 2000., iV0,
                        2,-0.5,1.5,AliReducedVarManager::kIsPileupMV);
      
      man->AddHistogram(classStr.Data(),"IsSPDpileupMultBins_SPDtracklets_V0","",kTRUE,
                        200, 0.0, 200., iTrk,
                         200, 0.0, 2000., iV0,
                        2,-0.5,1.5,AliReducedVarManager::kIsSPDPileupMultBins);
      
      man->AddHistogram(classStr.Data(),"IsT0pileup_SPDtracklets_V0","",kTRUE,
                        200, 0.0, 200., iTrk,
                         200, 0.0, 2000., iV0,
                        2,-0.5,1.5,AliReducedVarManager::kTZEROpileup);
      
      man->AddHistogram(classStr.Data(),"IsT0sattelite_SPDtracklets_V0","",kTRUE,
                        200, 0.0, 200., iTrk,
                         200, 0.0, 2000., iV0,
                        2,-0.5,1.5,AliReducedVarManager::kTZEROsatellite);

      
      
      
      
      
      
           man->AddHistogram(classStr.Data(),"VtxContributors_V0", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                         1000, 0., 1000.,iV0GainLossMax,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100., AliReducedVarManager::kNVtxContributors  );
      
      
           man->AddHistogram(classStr.Data(),"SPDVtxContributors_V0", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                         1000, 0., 1000.,iV0GainLossMax,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100., AliReducedVarManager::kNVtxSPDContributors  );
           
           
           
           
           
           man->AddHistogram(classStr.Data(),"Trk_V0", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                         1000, 0., 1000.,iV0,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100., iTrk  );
           
           
           
           man->AddHistogram(classStr.Data(),"Trk_V0online", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                         1000, 0., 20000.,AliReducedVarManager::kMultEstimatorOnlineV0M,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100., iTrk  );
           
           
           
           
           
           man->AddHistogram(classStr.Data(),"Trk_V0acCorr", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                        50, 0., 1000.,iV0ACCorrMax,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100., iTrkCorrMax  );
           
           
           
           
           
 
 
           
           man->AddHistogram(classStr.Data(),"TPCout_V0Corr", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                        50, 0., 1000.,iV0CorrMax,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100., AliReducedVarManager::kNTracksPerTrackingStatus + AliReducedVarManager::kTPCout  );
           
           
           man->AddHistogram(classStr.Data(),"Trk_V0Corr", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                        50, 0., 1000.,iV0CorrMax,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100., iTrkCorrMax  );
           
           man->AddHistogram(classStr.Data(),"Trk_V0CorrGainLoss", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                        50, 0., 1000.,iV0GainLossMax,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100., iTrkCorrMax  );
          
           
                     man->AddHistogram(classStr.Data(),"Trk_V0_Vtx", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                         1000, 0., 1000.,iV0,
                        20, -10., 10., AliReducedVarManager::kVtxZmc, 
                        100, 0., 100., iTrkCorrMax  );
           
           man->AddHistogram(classStr.Data(),"Trk_V0corr_Vtx", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                        50, 0., 1000.,iV0CorrMax,
                        20, -10., 10., AliReducedVarManager::kVtxZmc, 
                        100, 0., 100., iTrkCorrMax  );
           
           
           
           
           
           
           
           man->AddHistogram(classStr.Data(),"Trk_onlineV0", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                         600, 0., 6000.,AliReducedVarManager::kMultEstimatorOnlineV0M,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100., iTrk  );
              
              
              man->AddHistogram(classStr.Data(),"SelTracks_V0corr", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                        50, 0., 1000.,iV0GainLossMax,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100.,  AliReducedVarManager::kNtracksSelected);
              
              man->AddHistogram(classStr.Data(),"Analyzed_V0corr", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                        50, 0., 1000.,iV0GainLossMax,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100.,  AliReducedVarManager::kNtracksAnalyzed);
              
              
              
              
              
              man->AddHistogram(classStr.Data(),"runID_V0corr", "SPD #tracklets in |#eta|<1.0", kFALSE,          
                        nRuns, 0., nRuns,  AliReducedVarManager::kRunID,
                        1200, 0., 1200.,iV0GainLossMax,
                        0,0,0,-1, runNumbers.Data() );
              
              
              
              man->AddHistogram(classStr.Data(),"SelectedPairs_V0corr", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                        50, 0., 1000.,iV0GainLossMax,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100.,  AliReducedVarManager::kNpairsSelected);
              

              
              
              
              
              
              
              man->AddHistogram(classStr.Data(),"SelectedPairs_TrkCorr", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                        50, 0., 100., iTrkCorrMax,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100.,  AliReducedVarManager::kNpairsSelected);
              
              
              

              
              man->AddHistogram(classStr.Data(),"AnalyzedTracks_Trkcorr", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                        50, 0., 100., iTrkCorrMax,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100.,  AliReducedVarManager::kNtracksAnalyzed);
              
//               
      
      
      man->AddHistogram(classStr.Data(),"Trk_VZEROcorr_pairs","",kTRUE,
                        50, 0.0, 100., iTrkCorrMax,
                        20, 0.0, 1000., iV0GainLossMax,
                        100, 0., 100., AliReducedVarManager::kNpairsSelected                        
                       );
      
      man->AddHistogram(classStr.Data(),"Trk_VZEROcorr_tracks","",kTRUE,
                        50, 0.0, 100., iTrkCorrMax,
                        20, 0.0, 1000., iV0GainLossMax,
                        100, 0., 100., AliReducedVarManager::kNtracksAnalyzed                        
                       );
              
              
              
              man->AddHistogram(classStr.Data(),"VtxX_V0corr", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                        50, 0., 1000.,iV0GainLossMax,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100.,  AliReducedVarManager::kVtxX);
              man->AddHistogram(classStr.Data(),"VtxY_V0corr", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                        50, 0., 1000.,iV0GainLossMax,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100.,  AliReducedVarManager::kVtxY);
              man->AddHistogram(classStr.Data(),"VtxZ_V0corr", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                        50, 0., 1000.,iV0GainLossMax,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100.,  AliReducedVarManager::kVtxZ);
              
              
              man->AddHistogram(classStr.Data(),"VtxZ_V0gain", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                        50, 0., 1000.,iV0GainLossMax,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100.,  AliReducedVarManager::kVtxZ);
              
              
              man->AddHistogram(classStr.Data(),"VtxZ_V0", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                        50, 0., 1000.,iV0,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100.,  AliReducedVarManager::kVtxZ);
              
              
              
              
              man->AddHistogram(classStr.Data(),"VtxZ_V0gainCorr", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                        100, -10., 10.,  AliReducedVarManager::kVtxZmc,
                       
                        50, 0., 1000.,iV0GainLossMax
                        
                               );
              
              
              man->AddHistogram(classStr.Data(),"VtxZ_V0gainVtxCorr", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                        100, -10., 10.,  AliReducedVarManager::kVtxZmc,
                       
                        50, 0., 1000.,iV0GainLossMax
                        
                               );
              

              
              
              
              
              
              man->AddHistogram(classStr.Data(),"Analyzed_runNumber", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                         nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100.,  AliReducedVarManager::kNtracksAnalyzed,
                        runNumbers
                               );
              
              man->AddHistogram(classStr.Data(),"TPCout_runNumber", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                         nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100.,  AliReducedVarManager::kNTracksPerTrackingStatus + AliReducedVarManager::kTPCout,
                        runNumbers
                               );
              
              man->AddHistogram(classStr.Data(),"SelTracks_runNumber", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                         nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100.,  AliReducedVarManager::kNtracksSelected,
                        runNumbers
                               );
              man->AddHistogram(classStr.Data(),"SelPairs_runNumber", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                         nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100.,  AliReducedVarManager::kNpairsSelected,
                        runNumbers
                               );
              man->AddHistogram(classStr.Data(),"VtxX_runNumber", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                         nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100.,  AliReducedVarManager::kVtxX,
                        runNumbers
                               );
              


              man->AddHistogram(classStr.Data(),"VtxY_runNumber", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                         nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100.,  AliReducedVarManager::kVtxY,
                        runNumbers
                               );
              


              man->AddHistogram(classStr.Data(),"VtxZ_runNumber", "SPD #tracklets in |#eta|<1.0", kTRUE,  
                         nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                        2,0.,2., AliReducedVarManager::kINT7Triggered, 
                        100, 0., 100.,  AliReducedVarManager::kVtxZmc,
                        runNumbers
                               );
              



      man->AddHistogram(classStr.Data(),"V0A_VTX_Trigger_prof", "V0A mult", kFALSE, 
                         200,-10.,10.,AliReducedVarManager::kVtxZmc,
                        300, 0., 3000., iV0A );
      
      man->AddHistogram(classStr.Data(),"V0C_VTX_Trigger_prof", "V0C mult", kFALSE, 
                         200,-10.,10.,AliReducedVarManager::kVtxZmc, 
                        300, 0., 3000., iV0C );
      
      man->AddHistogram(classStr.Data(),"V0Acorrgain_VTX_Trigger_prof", "V0A mult", kFALSE, 
                         200,-10.,10.,AliReducedVarManager::kVtxZmc,
                        300, 0., 3000., iV0ACGainLossMax );
      
      man->AddHistogram(classStr.Data(),"V0Ccorrgain_VTX_Trigger_prof", "V0C mult", kFALSE, 
                         200,-10.,10.,AliReducedVarManager::kVtxZmc, 
                        300, 0., 3000., iV0CGainLossMax );
      
      man->AddHistogram(classStr.Data(),"V0Acorr_VTX_Trigger_prof", "V0A mult", kFALSE, 
                         200,-10.,10.,AliReducedVarManager::kVtxZmc,
                        300, 0., 3000., iV0ACCorrMax );
      
      man->AddHistogram(classStr.Data(),"V0Ccorr_VTX_Trigger_prof", "V0C mult", kFALSE, 
                         200,-10.,10.,AliReducedVarManager::kVtxZmc, 
                        300, 0., 3000., iV0CCorrMax );
      

      }

    
    }  // end if className contains "Event"    
    
   
    else  if(classStr.Contains("EventTag_")  && !SYSTEMATICS  ) {
      
      man->AddHistogram(classStr.Data(), "EventTag", "Event Tag", kFALSE, 17,-1.0, 16.0, AliReducedVarManager::kEventTag);

      
    man->AddHistogram(classStr.Data(),"RunNo_EventTag","",kFALSE, nRuns, 0, nRuns, AliReducedVarManager::kRunID, 
      17, -1, 16., AliReducedVarManager::kEventTag, 0,0,0,-1,
      runNumbers);
      
      man->AddHistogram(classStr.Data(),"Trigger_EventTag","",kFALSE, 2, 0, 2, AliReducedVarManager::kINT7Triggered, 
      17, -1, 16., AliReducedVarManager::kEventTag);
    
      
      
    }
    // Track histograms



    else if(classStr.Contains("Track")   && !SYSTEMATICS  ) {
      cout << classStr.Data() << endl;


      man->AddHistogram(classStr.Data(), "ITSClusterShared", "", kFALSE, 11, -1., 10.0, AliReducedVarManager::kITSnclsShared);
      
      
      man->AddHistogram(classStr.Data(), "ITSClusterSharedVsTracklets", "", kFALSE, 
        100, 0., 200.0, iTrk,
        6, 0., 6.0, AliReducedVarManager::kITSnclsShared
      );
      
      man->AddHistogram(classStr.Data(), "ITSClusterSharedVsTracklets_prof", "", kTRUE, 
        100, 0., 200.0, iTrk,
        6, 0., 6.0, AliReducedVarManager::kITSnclsShared
      );
      
      
      
      man->AddHistogram(classStr.Data(), "goldenChi2", "", kFALSE, 100, -1., 100.0, AliReducedVarManager::kChi2TPCConstrainedVsGlobal );

      
      man->AddHistogram(classStr.Data(), "goldenChi2_pt_prof", "", kTRUE, 
                        100, 0.0, 10.0, AliReducedVarManager::kPt,
                        200, 0., 2000.0,AliReducedVarManager::kChi2TPCConstrainedVsGlobal );
      

      man->AddHistogram(classStr.Data(), "goldenChi2VsTracklets_prof", "", kTRUE, 
        100, 0., 200.0, iTrk,
        100, 0., 1000.0, AliReducedVarManager::kChi2TPCConstrainedVsGlobal
      );
      

      man->AddHistogram(classStr.Data(), "Pt", "p_{T} distribution", kFALSE, 500, 0.0, 20.0, AliReducedVarManager::kPt);
      
      
      man->AddHistogram(classStr.Data(), "P", "p_{T} distribution", kFALSE, 500, 0.0, 20.0, AliReducedVarManager::kP);
      
      
      man->AddHistogram(classStr.Data(), "Eta", "", kFALSE, 500, -1., 1., AliReducedVarManager::kEta);
      man->AddHistogram(classStr.Data(), "Phi", "", kFALSE, 630, 0.0, 6.3, AliReducedVarManager::kPhi);

 
        man->AddHistogram(classStr.Data(),"Phi_Eta","TPC N_{#sigma} electron vs. #eta",kFALSE,
                          100,-1.,1.,AliReducedVarManager::kEta,64,0.,6.4,AliReducedVarManager::kPhi);
        
        
        
        
        
        man->AddHistogram(classStr.Data(),"Phi_Eta_dcaR","TPC N_{#sigma} electron vs. #eta",kTRUE,
                          2,-.8,.8,AliReducedVarManager::kEta,
                          90,0.,6.4,AliReducedVarManager::kPhi,
                          1000, -1.0, 1.0, AliReducedVarManager::kDcaXY);
        
        man->AddHistogram(classStr.Data(),"Phi_Eta_dcaZ","TPC N_{#sigma} electron vs. #eta",kTRUE,
                          2,-.8,.8,AliReducedVarManager::kEta,
                          90,0.,6.4,AliReducedVarManager::kPhi,
                          1000, -1.0, 1.0, AliReducedVarManager::kDcaZ);
        
        
        man->AddHistogram(classStr.Data(),"Phi_dcaR","TPC N_{#sigma} electron vs. #eta",kFALSE,
                          90,0.,6.4,AliReducedVarManager::kPhi,
                          100, -1.0, 1.0, AliReducedVarManager::kDcaXY);
        
        man->AddHistogram(classStr.Data(),"Phi_dcaZ","TPC N_{#sigma} electron vs. #eta",kFALSE,
                          90,0.,6.4,AliReducedVarManager::kPhi,
                          100, -3.0, 3.0, AliReducedVarManager::kDcaZ);
      
      
      man->AddHistogram(classStr.Data(), "DCAxy", "DCAxy", kFALSE, 1000, -1.0, 1.0, AliReducedVarManager::kDcaXY);
      
      
      man->AddHistogram(classStr.Data(), "DCAz", "DCAz", kFALSE, 600, -3.0, 3.0, AliReducedVarManager::kDcaZ);
      
      
      man->AddHistogram(classStr.Data(), "DCAz_DCAxy", "DCAz vs DCAxy", kFALSE, 
                        60, -3.0, 3.0, AliReducedVarManager::kDcaZ,
                        20, -1.0, 1.0, AliReducedVarManager::kDcaXY);
      
      
      man->AddHistogram(classStr.Data(), "DCAxy_Pt", "DCAxy_Pt", kFALSE, 90, 1.0, 10.0, AliReducedVarManager::kPt, 100, -1.0, 1.0, AliReducedVarManager::kDcaXY);
      man->AddHistogram(classStr.Data(), "DCAz_Pt", "DCAz_Pt", kFALSE, 90, 1.0, 10.0, AliReducedVarManager::kPt, 100, -3.0, 3.0, AliReducedVarManager::kDcaZ);
      
      

      
        man->AddHistogram(classStr.Data(),"ITSncls_Pt", "ITS nclusters vs. pT", kFALSE, 7,-0.5,6.5,AliReducedVarManager::kITSncls,
          90, 1.0, 10.0, AliReducedVarManager::kPt);


      
        man->AddHistogram(classStr.Data(),"ITSncls", "ITS nclusters", kFALSE, 7,-0.5,6.5,AliReducedVarManager::kITSncls);
	man->AddHistogram(classStr.Data(),"ITSchi2", "ITS #chi^{2}", kFALSE, 200,0.0,20.0, AliReducedVarManager::kITSchi2);
      
        man->AddHistogram(classStr.Data(),"TPCncls","",kFALSE,160,-0.5,159.5,AliReducedVarManager::kTPCncls);
	man->AddHistogram(classStr.Data(),"TPCcrossedRows","", kFALSE, 160,-0.5,159.5,AliReducedVarManager::kTPCcrossedRows);
	man->AddHistogram(classStr.Data(),"TPCnclsShared","",kFALSE, 160,-0.5,159.5,AliReducedVarManager::kTPCnclsShared);
	man->AddHistogram(classStr.Data(),"TPCchi2","",kFALSE, 510,-0.1,5.,AliReducedVarManager::kTPCchi2);
   
        man->AddHistogram(classStr.Data(),"Eta_TPCncls","TPC <nclusters> vs #eta", kFALSE,
                     100, -1., 1., AliReducedVarManager::kEta, 161, -1., 160, AliReducedVarManager::kTPCncls);

  
  
    man->AddHistogram(classStr.Data(),"P_TPCsignal","TPC <dEdx> vs p",kFALSE,
             100, 0.0, 10.0, AliReducedVarManager::kP, 
                     100, 0., 100., AliReducedVarManager::kTPCsignal);  
    
    
    
    man->AddHistogram(classStr.Data(),"P_TPCsignal_nSigma","TPC <dEdx> vs p",kTRUE,
             100, 0.0, 10.0, AliReducedVarManager::kP, 
                     120, 60., 120., AliReducedVarManager::kTPCsignal,
      100,0.,100.,  AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron 
   );  

  
        man->AddHistogram(classStr.Data(),"ratioClFind","ratio clusters/findable",kFALSE,
                     50,0.5,1.0,AliReducedVarManager::kTPCnclsRatio);
  
        man->AddHistogram(classStr.Data(),"TPCnsigElectron_Pin","TPC N_{#sigma} electron vs. inner param P",kFALSE,
                     790,0.1,8.0,AliReducedVarManager::kPin,120,-3.0,3.0,AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron);
        
        
        man->AddHistogram(classStr.Data(),"mult_Pt","TPC N_{#sigma} electron vs. inner param P",kTRUE,
                     120,0.,120, iTrk,
                     200,1.,8.0,AliReducedVarManager::kPt);


                
      
        man->AddHistogram(classStr.Data(),"TOFbeta_P","TOF #beta vs P",kFALSE,
                     200,0.0,10.0,AliReducedVarManager::kP, 110,0.0,1.1,AliReducedVarManager::kTOFbeta);
      
        
        
// QA profiles vs. run
        {
        
        
        
       man->AddHistogram(classStr.Data(),"RunNo_itsChi2","",1, nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                          2, 0.0, 2.,  AliReducedVarManager::kINT7Triggered,
                  100, 0.0, 100., AliReducedVarManager::kITSchi2, runNumbers);
       
       man->AddHistogram(classStr.Data(),"RunNo_tpcChi2","",1, nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                          2, 0.0, 2.,  AliReducedVarManager::kINT7Triggered,
                  100, 0.0, 10., AliReducedVarManager::kTPCchi2, runNumbers);
       
       
       man->AddHistogram(classStr.Data(),"RunNo_goldenChi2","",1, nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                          2, 0.0, 2.,  AliReducedVarManager::kINT7Triggered,
                  100, 0.0, 10., AliReducedVarManager::kChi2TPCConstrainedVsGlobal, runNumbers);
      
      
        man->AddHistogram(classStr.Data(),"RunNo_nClsTPC","",1,nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                          2, 0.0, 2.,  AliReducedVarManager::kINT7Triggered,
                  160, 0.0, 160., AliReducedVarManager::kTPCncls, runNumbers);
        
        man->AddHistogram(classStr.Data(),"RunNo_nClsITS","",1,nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                          2, 0.0, 2.,  AliReducedVarManager::kINT7Triggered,
                  160, 0.0, 160., AliReducedVarManager::kITSncls, runNumbers);
        
       man->AddHistogram(classStr.Data(),"RunNo_sharedClsITS","",1,nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                          2, 0.0, 2.,  AliReducedVarManager::kINT7Triggered,
                  160, 0.0, 160., AliReducedVarManager::kITSnclsShared, runNumbers);
        
        man->AddHistogram(classStr.Data(),"RunNo_eta","",1, nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                          2, 0.0, 2.,  AliReducedVarManager::kINT7Triggered,
                            180, -.9, .9, AliReducedVarManager::kEta, runNumbers);
                                                                       
        man->AddHistogram(classStr.Data(),"RunNo_phi","",1, nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                          2, 0.0, 2.,  AliReducedVarManager::kINT7Triggered,
                             630, 0.0, 6.3, AliReducedVarManager::kPhi,
                       runNumbers);
                                                                       
       man->AddHistogram(classStr.Data(),"RunNo_pt","",1, nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                          2, 0.0, 2.,  AliReducedVarManager::kINT7Triggered,
                                                                       100, 0.0, 10., AliReducedVarManager::kPt,
                      runNumbers);
        
        man->AddHistogram(classStr.Data(),"RunNo_dedx","",1, nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                          2, 0.0, 2.,  AliReducedVarManager::kINT7Triggered,
                                                                       100, 0.0, 200., AliReducedVarManager::kTPCsignal,
                        runNumbers);
        
        man->AddHistogram(classStr.Data(),"RunNo_signalN","",1, nRuns, 0, nRuns, AliReducedVarManager::kRunID,
                          2, 0.0, 2.,  AliReducedVarManager::kINT7Triggered,
                                                                       160, 0.0, 160., AliReducedVarManager::kTPCsignalN,
                        runNumbers);
        
        }
        
    
        
        
      
// QA profiles vs. V0M

{
        
        
        
             
        
             man->AddHistogram(classStr.Data(),"V0m_tpcChi2","",1, 100, 0, 1000, iV0GainLossMax,
                          
                  100, 0.0, 100., AliReducedVarManager::kTPCchi2);
        
      
        man->AddHistogram(classStr.Data(),"V0m_nClsTPC","",1,100, 0, 1000,iV0GainLossMax,
                          
                  160, 0.0, 160., AliReducedVarManager::kTPCncls);
      
        man->AddHistogram(classStr.Data(),"V0m_nClsITS","",1,100, 0, 1000,iV0GainLossMax,
                  160, 0.0, 160., AliReducedVarManager::kITSncls);
      
        


                                                                       
        
       man->AddHistogram(classStr.Data(),"V0m_pt","",1, 100, 0, 1000, iV0GainLossMax,
       100, 0.0, 10., AliReducedVarManager::kPt);
        
        
        
        man->AddHistogram(classStr.Data(),"V0m_sigmaEl","",kFALSE, 
                          100, 0, 1000, iV0GainLossMax,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron);
        
        
                
        man->AddHistogram(classStr.Data(),"V0m_sigmaProt","",kFALSE, 
                          100, 0, 1000, iV0GainLossMax,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kProton);
        
        
                
        man->AddHistogram(classStr.Data(),"V0m_sigmaPion","",kFALSE, 
                          100, 0, 1000, iV0GainLossMax,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion);
        
        
        
}      
// QA profiles vs. Trk

{
        
        
        
             
        
             man->AddHistogram(classStr.Data(),"Trk_tpcChi2","",1, 120, 0, 120, iTrkCorrMax,
                          
                  120, 0.0, 120., AliReducedVarManager::kTPCchi2);
        
      
        man->AddHistogram(classStr.Data(),"Trk_nClsTPC","",1,120, 0, 120,iTrkCorrMax,
                          
                  160, 0.0, 160., AliReducedVarManager::kTPCncls);
      
        man->AddHistogram(classStr.Data(),"Trk_nClsITS","",1,120, 0, 120,iTrkCorrMax,
                  160, 0.0, 160., AliReducedVarManager::kITSncls);
      
        


                                                                       
        
       man->AddHistogram(classStr.Data(),"Trk_pt","",1, 120, 0, 120, iTrkCorrMax,
       120, 0.0, 10., AliReducedVarManager::kPt);
        
        
        
        man->AddHistogram(classStr.Data(),"Trk_sigmaEl","",kFALSE, 
                          120, 0, 120, iTrkCorrMax,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron);
        
        
                
        man->AddHistogram(classStr.Data(),"Trk_sigmaProt","",kFALSE, 
                          120, 0, 120, iTrkCorrMax,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kProton);
        
        
                
        man->AddHistogram(classStr.Data(),"Trk_sigmaPion","",kFALSE, 
                          120, 0, 120, iTrkCorrMax,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion);
        
        
        
}




        

        /*
    
                man->AddHistogram(classStr.Data(),"pin_trk_nSigmaElectron","",kTRUE, 
                         30, 0.0, 6., AliReducedVarManager::kPin,
                         40, 0, 80, iTrkCorrMax,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron);
                
                man->AddHistogram(classStr.Data(),"pin_trk_nSigmaPion","",kTRUE, 
                         30, 0.0, 6., AliReducedVarManager::kPin,
                          40, 0, 80, iTrkCorrMax,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion);
                
                man->AddHistogram(classStr.Data(),"pin_v0_nSigmaElectron","",kTRUE, 
                         30, 0.0, 6., AliReducedVarManager::kPin,
                        50, 0, 1000, iV0GainLossMax,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron);
                
                man->AddHistogram(classStr.Data(),"pin_v0_nSigmaPion","",kTRUE, 
                         30, 0.0, 6., AliReducedVarManager::kPin,
                        50, 0, 1000, iV0GainLossMax,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion
                       );
                

                man->AddHistogram(classStr.Data(),"eta_trk_nSigmaElectron","",kTRUE, 
                         20, -0.8, 0.8, AliReducedVarManager::kEta,
                         40, 0, 80, iTrkCorrMax,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron);
                
                man->AddHistogram(classStr.Data(),"eta_trk_nSigmaPion","",kTRUE, 
                         20, -0.8, 0.8, AliReducedVarManager::kEta,
                         40, 0, 80, iTrkCorrMax,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion);
                
                man->AddHistogram(classStr.Data(),"eta_v0_nSigmaElectron","",kTRUE, 
                         20, -0.8, 0.8, AliReducedVarManager::kEta,
                        50, 0, 1000, iV0GainLossMax,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron
                       );
                
                man->AddHistogram(classStr.Data(),"eta_v0_nSigmaPion","",kTRUE, 
                         20, -0.8, 0.8, AliReducedVarManager::kEta,
                        50, 0, 1000, iV0GainLossMax,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion
                       );
                
                
                                                        
                man->AddHistogram(classStr.Data(),"pin_eta_nSigmaElectron","",kTRUE, 
                         30, 0.0, 6., AliReducedVarManager::kPin,
                        20, -0.8, 0.8, AliReducedVarManager::kEta,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron
                       );
                
                man->AddHistogram(classStr.Data(),"pin_eta_nSigmaPion","",kTRUE, 
                       30, 0.0, 6., AliReducedVarManager::kPin,
                        20, -0.8, 0.8, AliReducedVarManager::kEta,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion
                       );

                
                man->AddHistogram(classStr.Data(),"zvtx_trk_nSigmaElectron","",kTRUE, 
                         20, -10., 10., AliReducedVarManager::kVtxZmc,
                         40, 0, 80, iTrkCorrMax,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron);
                
                man->AddHistogram(classStr.Data(),"zvtx_trk_nSigmaPion","",kTRUE, 
                         20, -10., 10., AliReducedVarManager::kVtxZmc,
                         40, 0, 80, iTrkCorrMax,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion);
                
                man->AddHistogram(classStr.Data(),"zvtx_v0_nSigmaElectron","",kTRUE, 
                         20, -10., 10., AliReducedVarManager::kVtxZmc,
                        50, 0, 600, iV0GainLossMax,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron
                       );
                
                man->AddHistogram(classStr.Data(),"zvtx_v0_nSigmaPion","",kTRUE, 
                         20, -10., 10., AliReducedVarManager::kVtxZmc,
                        50, 0, 1000, iV0GainLossMax,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion
                       );
                
                
                                                        
                man->AddHistogram(classStr.Data(),"pin_zvtx_nSigmaElectron","",kTRUE, 
                         30, 0.0, 6., AliReducedVarManager::kPin,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron
                       );
                
                man->AddHistogram(classStr.Data(),"pin_zvtx_nSigmaPion","",kTRUE, 
                       30, 0.0, 6., AliReducedVarManager::kPin,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        60, -3., 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion
                       );*/

/*
 
        man->AddHistogram(classStr.Data(),"V0m_sigmaPi","",kFALSE, 
                          100, 0, 1000, iV0GainLossMax,
                        60, 3., 9., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion);
        
        man->AddHistogram(classStr.Data(),"trk_sigmaPi","",kFALSE, 
                          100, 0, 100, iTrkCorrMax,
                        60, 3., 9., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion);
        

         
         
        man->AddHistogram(classStr.Data(),"V0m_ITScls","",kFALSE, 
                          100, 0, 1000, iV0GainLossMax,6, 0., 6., AliReducedVarManager::kITSncls
                         );
        
        man->AddHistogram(classStr.Data(),"trk_ITScls","",kFALSE, 
                          100, 0, 100, iTrkCorrMax,
                           6, 0., 6., AliReducedVarManager::kITSncls);
        
        
        
        
        

        
        
        man->AddHistogram(classStr.Data(),"tpcOut_sigmaEl","",kFALSE, 
                          60, 0, 1200, AliReducedVarManager::kNTracksPerTrackingStatus+ AliReducedVarManager::kTPCout,
                        60, -3, 3., AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron);

        
        
       man->AddHistogram(classStr.Data(),"tpcOut_tpcChi2","",kFALSE,
                          100, 0, 2000, AliReducedVarManager::kNTracksPerTrackingStatus+ AliReducedVarManager::kTPCout,
                  100, 0.0, 4., AliReducedVarManager::kTPCchi2);
       */
        
        
    }  // end if "TrackQA"
    






// Histograms for pairs
    else if(classStr.Contains("Pair") || classStr.Contains("PureMCTruth_")   ) {

      
      bool mcTruth = classStr.Contains("PureMCTruth_");
     

 
    const Int_t kNMassBins =  12;
    Double_t massBins[kNMassBins];
    massBins[0] = 0.;
    massBins[1] = 2.8;
    for(Int_t i=2; i<kNMassBins-1; ++i) massBins[i] = 2.8 + .04 * (i-1); 
    massBins[kNMassBins-1] = 4.;

    const Int_t kNPtBins = 40;
    Double_t ptBins[kNPtBins] ={
      0.0, 0.2, 0.4, 0.6, 0.8,
      1.0, 1.2, 1.4, 1.6, 1.8,
      2.0, 2.2, 2.4, 2.6, 2.8,
      3.0, 3.2, 3.4, 3.6, 3.8,
      4.0, 4.4, 4.8, 5.2, 5.6,
      6.0, 6.8, 8.0, 9.0, 10.,
      11., 12., 13., 14., 15.,
      16., 17., 18., 19., 20.
    }; 


     const Int_t kNYBins = 6;
    Double_t yBins[kNYBins] = { 
       0.,  .7, .75,  .8, .85, .9};



     const Int_t nVarsPair = 4;
      
    
    Int_t massVar = mcTruth? (AliReducedVarManager::kMassMC) : (AliReducedVarManager::kMass);
   Int_t ptVar = mcTruth? (AliReducedVarManager::kPtMC) : (AliReducedVarManager::kPt);
   // Int_t ptVar = mcTruth? (AliReducedVarManager::kPMC) : (AliReducedVarManager::kP);
    Int_t yVar = mcTruth? (AliReducedVarManager::kRapMCAbs) : (AliReducedVarManager::kRapAbs);
      
      Int_t varsPair[nVarsPair] = {
        multEstimator, 
        massVar, 
        ptVar,
        yVar }; 

      TArrayD pairHistBinLimits[nVarsPair];
   //   pairHistBinLimits[0] = TArrayD( kNperiodBins,      periodBins);
//       pairHistBinLimits[0] = TArrayD( kNMBBins,      mbBins);
//       pairHistBinLimits[1] = TArrayD( kNVtxBins,      vtxBins);
      pairHistBinLimits[0] = TArrayD( nMultBinLimits, multBinLimits);
      pairHistBinLimits[1] = TArrayD( kNMassBins,    massBins);
      pairHistBinLimits[2] = TArrayD( kNPtBins,      ptBins);
      pairHistBinLimits[3] = TArrayD( kNYBins,      yBins);
    
       man->AddHistogram(classStr.Data(), "PairInvMass", "Differential pair inv. mass", nVarsPair, varsPair, pairHistBinLimits );

      man->AddHistogram(classStr.Data(),"RunID","Run IDs",kFALSE,nRuns, 0., nRuns, AliReducedVarManager::kRunID );
      man->AddHistogram(classStr.Data(),"Period","period",kFALSE, nPeriods, 0., nPeriods, AliReducedVarManager::kPeriod, 0,0,0,-1,0,0,0,-1, periods.Data()  );
      man->AddHistogram(classStr.Data(),"Mult","mult",kFALSE, 100, 0., 100.,  AliReducedVarManager::kNch10 );
      man->AddHistogram(classStr.Data(),"Pt_Period","period",kFALSE, 
        100, 0., 10., ptVar,
        nPeriods, 0., nPeriods, AliReducedVarManager::kPeriod, 0,0,0,-1, periods.Data()  );
      

// 
//         man->AddHistogram(classStr.Data(), "massCorr", "", kFALSE,
//                           400, -.1,.1, AliReducedVarManager::kMassDcaPtCorr);
 
/*              
        man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMax_Pt_VtxEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20., iTrkCorrMax,
                        20, 0., 20., ptVar,
            201, -1., 200., AliReducedVarManager::kHasVtx );
        
        man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMax_VtxEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20., iTrkCorrMax,
            201, -1., 200., AliReducedVarManager::kHasVtx );
        
        
        
      man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMax_Pt_TriggerEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20., iTrkCorrMax,
                        20, 0., 20., ptVar,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
        
      
      
      
      man->AddHistogram(classStr.Data(),"Nch10_Pt_TriggerEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20.,  AliReducedVarManager::kNch10,
                        20, 0., 20., ptVar,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      man->AddHistogram(classStr.Data(),"Nch16_Pt_TriggerEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20.,  AliReducedVarManager::kNch16,
                        20, 0., 20., ptVar,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
        
      
      
      
      man->AddHistogram(classStr.Data(),"Nch10JpsiExcl_Pt_TriggerEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20.,  AliReducedVarManager::kNch10JpsiExcl,
                        20, 0., 20., ptVar,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      man->AddHistogram(classStr.Data(),"Nch16JpsiExcl_Pt_TriggerEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20.,  AliReducedVarManager::kNch16JpsiExcl,
                        20, 0., 20., ptVar,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      man->AddHistogram(classStr.Data(),"NchV0_Pt_TriggerEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20.,  AliReducedVarManager::kNchV0,
                        20, 0., 20., ptVar,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      man->AddHistogram(classStr.Data(),"NchV0or_Pt_TriggerEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20.,  AliReducedVarManager::kNchV0or,
                        20, 0., 20., ptVar,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      man->AddHistogram(classStr.Data(),"V0or_Pt_TriggerEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 2.,  AliReducedVarManager::kV0or,
                        20, 0., 20., ptVar,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      man->AddHistogram(classStr.Data(),"V0or_TriggerEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 2., AliReducedVarManager::kV0or ,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      man->AddHistogram(classStr.Data(),"V0A_TriggerEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20., iV0A,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      man->AddHistogram(classStr.Data(),"V0C_TriggerEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20., iV0C,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      man->AddHistogram(classStr.Data(),"NchV0or_VtxZ_TriggerEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 2.,  AliReducedVarManager::kNchV0or,
                        20, -10., 10., AliReducedVarManager::kVtxZmc,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      man->AddHistogram(classStr.Data(),"NchMidOrV0_Pt_TriggerEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20.,  AliReducedVarManager::kNchMidOrV0,
                        20, 0., 20., ptVar,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
      
      
      
      man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMax_TriggerEff", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kTRUE,
                        20, 0., 20., iTrkCorrMax,
                        201, -1., 200., AliReducedVarManager::kINT7Triggered );
        */
        

//         man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMax_Pt", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kFALSE,
//                         100, 0., 100., iTrkCorrMax,
//                         100, 0., 10., ptVar);
// 
//         man->AddHistogram(classStr.Data(),"SPDntrackletsCorrMax", "corrected SPD #tracklets in |#eta|<1.0 (max mult)", kFALSE,
//                         20, 0., 20., iTrkCorrMax);

        
        


       /*
       
          
        man->AddHistogram(classStr.Data(), "mult_Mass", "", kFALSE,
                          20, 0., 1000., multEstimator,
                          400, 0.,.2, AliReducedVarManager::kMass);
        
               
              man->AddHistogram(classStr.Data(), "mult_CorrMass", "", kFALSE,
                          20, 0., 1000., multEstimator,
                          400, -.1,.1, AliReducedVarManager::kMassDcaPtCorr);
        
        
          
        man->AddHistogram(classStr.Data(), "trk_deltaEta", "", kFALSE,
                          20, 0., 100., iTrkCorrMax,
                          32, 0., 1.6 , AliReducedVarManager::kDeltaEta);
        
        
        
        
        
                
        man->AddHistogram(classStr.Data(), "mult_deltaPhi", "", kFALSE,
                          20, 0., 1000., multEstimator,
                          36, 0., 6.3 , AliReducedVarManager::kDeltaPhi);
        
        man->AddHistogram(classStr.Data(), "mult_openingAngle", "", kFALSE,
                          20, 0., 1000., multEstimator,
                          36, 0., 6.3 , AliReducedVarManager::kPairOpeningAngle);
        
        
                man->AddHistogram(classStr.Data(), "mult_Eta", "", kFALSE,
                          20, 0., 1000., multEstimator,
                          32, -0.8, 0.8 , AliReducedVarManager::kEta);
        
        man->AddHistogram(classStr.Data(), "mult_Phi", "", kFALSE,
                          20, 0., 1000., multEstimator,
                          36, 0., 6.3 , AliReducedVarManager::kPhi);
        
        
        man->AddHistogram(classStr.Data(), "mult_Pt", "", kFALSE,
                          20, 0., 1000., multEstimator,
                         50, 0.,10., AliReducedVarManager::kPt);
        

        
        
        */
       
      if(0&& !SYSTEMATICS ){
        
                
    Int_t rapVar = mcTruth? (AliReducedVarManager::kRapMC) : (AliReducedVarManager::kRap);
        
        
        
        man->AddHistogram(classStr.Data(), "Rapidity", "Rapidity", kFALSE, 200, -1., 1., rapVar);
        man->AddHistogram(classStr.Data(), "Rapidity_Pt", "Rapidity_Pt", kFALSE,
                        80, -.8, .8, rapVar,
                        100, 0., 10., ptVar);
        
        
        
        man->AddHistogram(classStr.Data(), "Mass_Pt", "Rapidity_Pt", kFALSE,
                        150, 0., 6., AliReducedVarManager::kMass,
                        100, 0., 10., ptVar);
        
        
        man->AddHistogram(classStr.Data(), "PairType", "Pair type", kFALSE, 4, -0.5, 3.5, AliReducedVarManager::kPairType);
       man->AddHistogram(classStr.Data(), "Mass", "Invariant mass", kFALSE, 1500, 0., 15.0, AliReducedVarManager::kMass);
        man->AddHistogram(classStr.Data(), "Pt", "", kFALSE, 100, 0.0, 10.0, AliReducedVarManager::kPt);
        man->AddHistogram(classStr.Data(), "Rapidity", "Rapidity", kFALSE, 300, -1.5, 1.5, AliReducedVarManager::kRap);
        man->AddHistogram(classStr.Data(), "Eta", "Eta", kFALSE, 240, -1.2, 1.2, AliReducedVarManager::kEta);
        man->AddHistogram(classStr.Data(), "Phi", "Azimuthal distribution", kFALSE, 630, 0.0, 6.3, AliReducedVarManager::kPhi);
        
        
        


        man->AddHistogram(classStr.Data(), "Rap_Mass", "", kFALSE,
                          200, -1, 1., AliReducedVarManager::kRap,
                          300, 0.,6., AliReducedVarManager::kMass);
        
        man->AddHistogram(classStr.Data(), "Eta_Mass", "", kFALSE,
                          200, -4, 4., AliReducedVarManager::kEta,
                          300, 0.,6., AliReducedVarManager::kMass);
        
        man->AddHistogram(classStr.Data(), "Eta_Pt", "", kFALSE,
                          200, -2, 2., AliReducedVarManager::kEta,
                          200, 0.,20., AliReducedVarManager::kPt);
        
        
        
        man->AddHistogram(classStr.Data(), "OpeningAngleMass", "", kFALSE,
                          160, 0, 3.2, AliReducedVarManager::kPairOpeningAngle,
                          300, 0., 6., AliReducedVarManager::kMass);
        
        man->AddHistogram(classStr.Data(), "TrackletsMass", "", kFALSE,
                          24, 0, 120, AliReducedVarManager::kMultiplicity + AliReducedVarManager::kSPDntracklets,
                          300, 0., 6., AliReducedVarManager::kMass);
        
        man->AddHistogram(classStr.Data(), "PtMass", "", kFALSE,
                          100, 0., 10., AliReducedVarManager::kPt,
                          100, 0., 10., AliReducedVarManager::kMass);
        
        man->AddHistogram(classStr.Data(), "PhiMass", "", kFALSE,
                          315, 0., 6.30, AliReducedVarManager::kPhi,
                          300, 0., 6., AliReducedVarManager::kMass);
        
        man->AddHistogram(classStr.Data(), "PhiPt", "", kFALSE,
                          315, 0., 6.30, AliReducedVarManager::kPhi,
                          300, 0., 6., AliReducedVarManager::kPt);


        
        
        man->AddHistogram(classStr.Data(), "Vtx_Mass", "", kFALSE,
                          20, -10.,10., AliReducedVarManager::kVtxZmc,
                         300, 0., 6., AliReducedVarManager::kMass);
        
        
       if ( classStr.Contains("PairSE") || classStr.Contains("PairPrefilterSE") ) ) {
         
         
         
        man->AddHistogram(classStr.Data(), "Phiv", "Phiv distribution", kFALSE, 630, 0., 3.15, AliReducedVarManager::kPairPhiV);
         
        man->AddHistogram(classStr.Data(), "OpeningAngle", "", kFALSE, 315, 0.0, 3.15, AliReducedVarManager::kPairOpeningAngle);  
        
        
        
        man->AddHistogram(classStr.Data(), "OpeningAnglePt", "", kFALSE,
                          160, 0, 3.2, AliReducedVarManager::kPairOpeningAngle,
                          200, 0., 10., AliReducedVarManager::kPt);
        
        
        
        man->AddHistogram(classStr.Data(), "OpeningAnglePhi", "", kFALSE,
                          315, 0., 6.3, AliReducedVarManager::kPhi,
                          300, 0., 6., AliReducedVarManager::kPairOpeningAngle);
        
         man->AddHistogram(classStr.Data(), "CorrectedMass", "Invariant mass, DCA corrected", kFALSE, 1500, 0., 15.0, AliReducedVarManager::kMassDcaPtCorr);
        
         man->AddHistogram(classStr.Data(), "MassCorrectedMass", "Invariant mass, DCA corrected", kFALSE, 
           250, 0., 5.0, AliReducedVarManager::kMassDcaPtCorr,
           250, 0., 5.0, AliReducedVarManager::kMass
        );
        
                
        man->AddHistogram(classStr.Data(), "PairDcaSqrt", "", kFALSE,
                          
                          400, 0.,2., AliReducedVarManager::kPairDcaXYSqrt);
        
        
        man->AddHistogram(classStr.Data(), "PairDcaSqrt_Mass", "", kFALSE,
                          200, 0.,1., AliReducedVarManager::kPairDcaXYSqrt,
                         300, 0., 6., AliReducedVarManager::kMass
        );
        
        
        
        
        man->AddHistogram(classStr.Data(), "PairDca", "", kFALSE,
                          400, 0.,4., AliReducedVarManager::kPairDcaXY);
        
        
        
        
        man->AddHistogram(classStr.Data(),"v0m_Mass","",1,
                          100, 0., 1000., iV0,
            100, 0.0, 100., AliReducedVarManager::kMass);
        
        man->AddHistogram(classStr.Data(),"v0m_OpeningAngle","",1,
                          100, 0., 1000., iV0,
            100, 0.0, 100., AliReducedVarManager::kPairOpeningAngle);
        
        
        
        man->AddHistogram(classStr.Data(),"v0m_Pt","",1,
                          100, 0., 1000., iV0,
            100, 0.0, 100., AliReducedVarManager::kPt);

        
        
        
//         man->AddHistogram(classStr.Data(), "OpeningAngle", "opening angle distribution", kFALSE, 315, 0., 3.15, AliReducedVarManager::kPairOpeningAngle);
        
//
        
        
        /*
         man->AddHistogram(classStr.Data(), "Phiv_Mass", "", kFALSE,
                           316, -0.01, 3.15, AliReducedVarManager::kPairPhiV,
                           300, 0.,6., AliReducedVarManager::kMass);
        
        
        
        
         man->AddHistogram(classStr.Data(), "Phiv_OpeningAngle", "", kFALSE,
                           316, -0.01, 3.15, AliReducedVarManager::kPairPhiV,
                           200, 0.,.2, AliReducedVarManager::kPairOpeningAngle);
        
//                 man->AddHistogram(classStr.Data(), "Mass_CorrectedMass", "", kFALSE,
//                           200, 2.3, 3.3, AliReducedVarManager::kMass,
//                           200, 2.3, 3.3, AliReducedVarManager::kMassDcaPtCorr);
        
        
        
         man->AddHistogram(classStr.Data(), "Phiv_OpeningAngleCorr", "", kFALSE,
                           315, 0., 3.15, AliReducedVarManager::kPairPhiV,
                           400, -.1,.3, AliReducedVarManager::kOpAngDcaPtCorr);
         
         
         
         
         man->AddHistogram(classStr.Data(), "Phiv_PairDcaSqrt", "", kFALSE,
                           315, 0., 3.15, AliReducedVarManager::kPairPhiV,
                           400, 0.,1., AliReducedVarManager::kPairDcaXYSqrt);
         
         man->AddHistogram(classStr.Data(), "Phiv_PairDca", "", kFALSE,
                           315, 0., 3.15, AliReducedVarManager::kPairPhiV,
                           400, 0.,1., AliReducedVarManager::kPairDcaXY);
        
        
        
        
        
        

        man->AddHistogram(classStr.Data(), "Phiv_CorrectedMass", "", kFALSE,
                316, -0.01, 3.15, AliReducedVarManager::kPairPhiV,
                200, -.1,.3, AliReducedVarManager::kMassDcaPtCorr);



              man->AddHistogram(classStr.Data(),"RunNo_Pt","",1, nRuns, 0, nRuns, AliReducedVarManager::kRunID, 
                2, 0.0, 2.,  AliReducedVarManager::kINT7Triggered,
              100, -4, 4., AliReducedVarManager::kPt,
              runNumbers);


        man->AddHistogram(classStr.Data(),"SPDnTrk_Pt","",1, 120, 0, 120, iTrk,
                2, 0.0, 2.,  AliReducedVarManager::kINT7Triggered,
            100, 0.0, 100., AliReducedVarManager::kPt);



              man->AddHistogram(classStr.Data(),"RunNo_Mass","",1, nRuns, 0, nRuns, AliReducedVarManager::kRunID, 
                2, 0.0, 2.,  AliReducedVarManager::kINT7Triggered,
              100, -4, 4., AliReducedVarManager::kMass,
              runNumbers);




              man->AddHistogram(classStr.Data(),"RunNo_OpAng","",1, nRuns, 0, nRuns, AliReducedVarManager::kRunID, 
                2, 0.0, 2.,  AliReducedVarManager::kINT7Triggered,
              100, -4, 4., AliReducedVarManager::kPairOpeningAngle,
              runNumbers);


        man->AddHistogram(classStr.Data(),"SPDnTrk_OpAng","",1, 120, 0, 120, iTrk,
                2, 0.0, 2.,  AliReducedVarManager::kINT7Triggered,
            100, 0.0, 100., AliReducedVarManager::kPairOpeningAngle);

                
                
                
                
             

        man->AddHistogram(classStr.Data(), "CorrOpAng_pairDCAxySqrt_OneOverSqrtPt", "", 1,
                          200, 0., 1., AliReducedVarManager::kPairDcaXYSqrt,
                          50, 0.1, 0.7, AliReducedVarManager::kOneOverSqrtPt,
                          200, -1., .3, AliReducedVarManager::kOpAngDcaPtCorr);
        
        man->AddHistogram(classStr.Data(), "CorrOpAng_OneOverSqrtPt", "", 0,
                          200, -.1, .3, AliReducedVarManager::kOpAngDcaPtCorr,
                          50, 0.1, 0.7, AliReducedVarManager::kOneOverSqrtPt);
        
        man->AddHistogram(classStr.Data(), "CorrOpAng_pairDCAxySqrt", "", 0,
                          200, -.1, .3, AliReducedVarManager::kOpAngDcaPtCorr,
                          400, 0., 1., AliReducedVarManager::kPairDcaXYSqrt);
        
        
        
        man->AddHistogram(classStr.Data(), "OpAng_pairDCAxySqrt_OneOverSqrtPt", "", 1,
                          400, 0., 2., AliReducedVarManager::kPairDcaXYSqrt,
                          50, 0.1, 0.7, AliReducedVarManager::kOneOverSqrtPt,
                          200, -1., .3, AliReducedVarManager::kPairOpeningAngle);
        
        man->AddHistogram(classStr.Data(), "OpAng_OneOverSqrtPt", "", 0,
                          200, -.1, .3, AliReducedVarManager::kPairOpeningAngle,
                          50, 0.1, 0.7, AliReducedVarManager::kOneOverSqrtPt);
        
        man->AddHistogram(classStr.Data(), "OpAng_pairDCAxySqrt", "", 0,
                          200, -.1, .3, AliReducedVarManager::kPairOpeningAngle,
                          400, 0., 1., AliReducedVarManager::kPairDcaXYSqrt);
        
        
        
        
               
        man->AddHistogram(classStr.Data(), "CorrMass_pairDCAxySqrt_Pt", "", 1,
                          400, 0.,2., AliReducedVarManager::kPairDcaXYSqrt,
                           50, 0.6, 5.6, AliReducedVarManager::kPt,
                          300, -.1, .2, AliReducedVarManager::kMassDcaPtCorr);
        
               
        man->AddHistogram(classStr.Data(), "CorrMass_Pt", "", 0,
                          300, -.1, .2, AliReducedVarManager::kMassDcaPtCorr,
                           50, 0.6, 5.6, AliReducedVarManager::kPt);
        
               
        man->AddHistogram(classStr.Data(), "CorrMass_pairDCAxySqrt", "", 0,
                          300, -.1, .2, AliReducedVarManager::kMassDcaPtCorr,
                          400, 0., 1., AliReducedVarManager::kPairDcaXYSqrt);
               
        
        
        
        man->AddHistogram(classStr.Data(), "Mass_pairDCAxySqrt_Pt", "", 1,
                          400, 0., 2., AliReducedVarManager::kPairDcaXYSqrt,
                           50, 0.6, 5.6, AliReducedVarManager::kPt,
                          300, -.1, .2, AliReducedVarManager::kMass);
        
        
               
        man->AddHistogram(classStr.Data(), "Mass_pairDCAxySqrt", "", 0,
                          300, -.1, .2, AliReducedVarManager::kMass,
                          400, 0., 1., AliReducedVarManager::kPairDcaXYSqrt);
        
        
        */
        
        }  
      }
    }   // end if for Pair classes of histograms
 
    
    
    
    
    
//       if(classStr.Contains("PureMCTruth_")) {
//        man->AddHistClass(classStr.Data());
//        cout << classStr.Data() << endl;
//        
//        
//        man->AddHistogram(classStr.Data(), "MassMC", "MC mass", kFALSE, 200, 0., 5.0, AliReducedVarManager::kMassMC);
//        man->AddHistogram(classStr.Data(), "RapidityMC", "MC rapidity", kFALSE, 48, -1.2, 1.2, AliReducedVarManager::kRapMC);
//        man->AddHistogram(classStr.Data(), "PtMC", "p_{T} MC", kFALSE, 1000, 0., 10.0, AliReducedVarManager::kPtMC);
//        man->AddHistogram(classStr.Data(), "PtMC_coarse", "p_{T} MC", kFALSE, 20, 0., 20.0, AliReducedVarManager::kPtMC);
//        man->AddHistogram(classStr.Data(), "PhiMC", "MC #varphi", kFALSE, 100, 0., 6.3, AliReducedVarManager::kPhiMC);
//        man->AddHistogram(classStr.Data(), "EtaMC", "MC #eta", kFALSE, 100, -1.5, 1.5, AliReducedVarManager::kEtaMC);
//        man->AddHistogram(classStr.Data(), "PtMC_RapMC", "", kFALSE, 100, -1.2, 1.2, AliReducedVarManager::kRapMC, 100, 0., 15., AliReducedVarManager::kPtMC);
// 
//        
//        continue;
//     }
    
    
    
  }  // end loop over histogram classes
}





//__________________________________________________________________________________________
AliAnalysisTask* AddTask_sweber_jpsi2eeMC(Bool_t isAliRoot=kTRUE, Int_t runMode=1, TString prod="LHC10h", Int_t runNumber=0){    
   //
   // isAliRoot=kTRUE for ESD/AOD analysis in AliROOT, kFALSE for root analysis on reduced trees
   // runMode=1 (AliAnalysisTaskReducedEventProcessor::kUseOnTheFlyReducedEvents)
   //               =2 (AliAnalysisTaskReducedEventProcessor::kUseEventsFromTree)
   //
   //get the current analysis manager

  printf("INFO on AddTask_sweber_jpsi2ee(): (isAliRoot, runMode) :: (%d,%d) \n", isAliRoot, runMode);

  AliReducedAnalysisJpsi2eeMult* jpsi2eeAnalysis = new AliReducedAnalysisJpsi2eeMult("Jpsi2eeAnalysis","Jpsi->ee analysis");
  jpsi2eeAnalysis->Init();
  Setup(jpsi2eeAnalysis, prod, runNumber);
  // initialize an AliAnalysisTask which will wrapp the AliReducedAnalysisJpsi2eeMult such that it can be run in an aliroot analysis train (e.g. LEGO, local analysis etc)
  AliAnalysisTaskReducedEventProcessor* task = new AliAnalysisTaskReducedEventProcessor("ReducedEventAnalysisManager", runMode);
  task->AddTask(jpsi2eeAnalysis);
  
  if(isAliRoot){
     AliAnalysisManager *mgr = AliAnalysisManager::GetAnalysisManager();
     if (!mgr) {
        Error("AddTask_iarsene_dst", "No analysis manager found.");
        return 0;
     }
     
     AliAnalysisDataContainer* cReducedEvent = NULL;
     if(runMode==AliAnalysisTaskReducedEventProcessor::kUseOnTheFlyReducedEvents) {
       printf("INFO on AddTask_sweber_jpsi2ee(): use on the fly events ");
       cReducedEvent = (AliAnalysisDataContainer*)mgr->GetContainers()->FindObject("ReducedEventDQ");
       if(!cReducedEvent) {
         printf("ERROR: In AddTask_sweber_jpsi2ee(), couldn't find exchange container with ReducedEvent! ");
         printf("             You need to use AddTask_iarsene_dst() in the on-the-fly reduced events mode!");
         return 0x0;
       }
     }
            
     mgr->AddTask(task);
      
     if(runMode==AliAnalysisTaskReducedEventProcessor::kUseEventsFromTree) 
        mgr->ConnectInput(task,  0, mgr->GetCommonInputContainer());
      
     if(runMode==AliAnalysisTaskReducedEventProcessor::kUseOnTheFlyReducedEvents) 
       mgr->ConnectInput(task, 0, cReducedEvent);
  
     AliAnalysisDataContainer *cOutputHist = mgr->CreateContainer("jpsi2eeHistos", THashList::Class(),
            AliAnalysisManager::kOutputContainer, "dstAnalysisHistograms.root");
     mgr->ConnectOutput(task, 1, cOutputHist );
  }
  else {
    // nothing at the moment   
  }
  
  return task;
}

AliReducedTrackCut *SetTrackCuts(
  TString name = "default",
  Double_t eta = .8,
  Double_t dcaxy = 1.,
  Double_t dcaz = 3.,
  Double_t nclsTPC = 70.,
  Double_t nclsITS = 3.,
  Double_t chi2 = 4.,
  Double_t nsigmaElectronLow = -2.,
  Double_t nsigmaElectronUp = 3.,
  Double_t nSigmaPion = 3.,
  Double_t nSigmaProton = 3.5,
  Int_t rejectKinks = 1,
  Int_t  spd = 1,
  Double_t pt =1.
){
  AliReducedTrackCut *trackCut1 = new AliReducedTrackCut(name.Data(), name.Data());
  trackCut1->AddCut(AliReducedVarManager::kPt, pt,100.0);
  trackCut1->AddCut(AliReducedVarManager::kEta, -1.*eta, eta);
  trackCut1->AddCut(AliReducedVarManager::kDcaXY, -1. * dcaxy, dcaxy);
  trackCut1->AddCut(AliReducedVarManager::kDcaZ, -1. * dcaz, dcaz);
  trackCut1->AddCut(AliReducedVarManager::kTPCncls, nclsTPC,160.0);
  trackCut1->AddCut(AliReducedVarManager::kITSncls, nclsITS,9.0);
  trackCut1->AddCut(AliReducedVarManager::kTPCchi2, 0., chi2);
  trackCut1->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kProton, nSigmaProton, 1.0e+30);
  trackCut1->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kPion, nSigmaPion, 1.0e+30);
  trackCut1->AddCut(AliReducedVarManager::kTPCnSig+AliReducedVarManager::kElectron, nsigmaElectronLow, nsigmaElectronUp);
  if (rejectKinks ==1 ) trackCut1->SetRejectKinks();
  trackCut1->SetRequestITSrefit();
  trackCut1->SetRequestTPCrefit();
  if(spd ==1) trackCut1->SetRequestSPDany();
  if(spd ==2) trackCut1->SetRequestSPDfirst();
  if(spd ==3) trackCut1->SetRequestSPDboth();
  
  return trackCut1;
}


//_________________________________________________________________
void SetupHistogramManager(AliReducedAnalysisJpsi2eeMult* task, TString prod , TString runNumbers, Int_t multEstimator ) {
  //
  // setup the histograms manager
  //
  AliReducedVarManager::SetDefaultVarNames();
  
  DefineHistograms(task, prod, runNumbers, multEstimator);
  
  AliReducedVarManager::SetUseVars(task->GetHistogramManager()->GetUsedVars());
}



//_________________________________________________________________
void SetupMixingHandler(AliReducedAnalysisJpsi2eeMult* task, Int_t multEstimator) {
   //
   // setup the mixing handler
   //
   AliMixingHandler* handler = task->GetMixingHandler();
   handler->SetPoolDepth(200);
   handler->SetMixingThreshold(1.0);
   handler->SetDownscaleEvents(1);
   handler->SetDownscaleTracks(1);
   


   const Int_t nTrkBinLimits =  2;
   Float_t trkBinLimits[nTrkBinLimits] ={0., 2000.};  

/*
   const Int_t nTrkBinLimits =  27;
   Float_t trkBinLimits[nTrkBinLimits] ={  
     0., 50., 100.,150.,200.,
     250.,300.,350.,400.,450.,
     500.,550., 600., 650., 700., 
     750., 800.,850., 900., 950., 
     1000.,1100., 1200., 1300., 1400.,
     1500.,2000.};
*/
 
    
//    const Int_t nZbinLimits = 7;
//    Float_t zLims[nZbinLimits] = {-500.,-200., -100. 0.,  100., 200., 500. };
    
   const Int_t nZbinLimits = 2;
   Float_t zLims[nZbinLimits] = {-10., /*  -8.,  -6.,  -4.,  -2., 0.,  2.,  4.,  6.,  8., */10. };

   
//   const Int_t nTriggerbinLimits = 3;
//   Float_t triggerLims[nTriggerbinLimits] = {0.  , 1., 2. };
   
   const Int_t nTriggerbinLimits = 2;
   Float_t triggerLims[nTriggerbinLimits] = {0., /*1.,*/ 2. };
  

   handler->AddMixingVariable(multEstimator, nTrkBinLimits, trkBinLimits);
   handler->AddMixingVariable(AliReducedVarManager::kVtxZmc, nZbinLimits, zLims);
   handler->AddMixingVariable( AliReducedVarManager::kINT7Triggered, nTriggerbinLimits, triggerLims);
 
}
