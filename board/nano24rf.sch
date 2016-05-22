<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="6.6.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="Arduino-clone">
<description>Arduino Clone pinheaders
By cl@xganon.com
http://www.xganon.com</description>
<packages>
<package name="NANO">
<pad name="TX0" x="5.08" y="-8.89" drill="0.8" shape="long"/>
<pad name="RX1" x="5.08" y="-6.35" drill="0.8" shape="long"/>
<pad name="RST1" x="5.08" y="-3.81" drill="0.8" shape="long"/>
<pad name="GND1" x="5.08" y="-1.27" drill="0.8" shape="long"/>
<pad name="D2" x="5.08" y="1.27" drill="0.8" shape="long"/>
<pad name="D3" x="5.08" y="3.81" drill="0.8" shape="long"/>
<pad name="D4" x="5.08" y="6.35" drill="0.8" shape="long"/>
<pad name="D5" x="5.08" y="8.89" drill="0.8" shape="long"/>
<pad name="D6" x="5.08" y="11.43" drill="0.8" shape="long"/>
<pad name="D7" x="5.08" y="13.97" drill="0.8" shape="long"/>
<pad name="D8" x="5.08" y="16.51" drill="0.8" shape="long"/>
<pad name="D9" x="5.08" y="19.05" drill="0.8" shape="long"/>
<pad name="RAW" x="-10.16" y="-8.89" drill="0.8" shape="long"/>
<pad name="GND" x="-10.16" y="-6.35" drill="0.8" shape="long"/>
<pad name="RST" x="-10.16" y="-3.81" drill="0.8" shape="long"/>
<pad name="A3" x="-10.16" y="11.43" drill="0.8" shape="long"/>
<pad name="A2" x="-10.16" y="13.97" drill="0.8" shape="long"/>
<pad name="A1" x="-10.16" y="16.51" drill="0.8" shape="long"/>
<pad name="A0" x="-10.16" y="19.05" drill="0.8" shape="long"/>
<pad name="D13" x="-10.16" y="26.67" drill="0.8" shape="long"/>
<pad name="D12" x="5.08" y="26.67" drill="0.8" shape="long"/>
<pad name="D11" x="5.08" y="24.13" drill="0.8" shape="long"/>
<pad name="D10" x="5.08" y="21.59" drill="0.8" shape="long"/>
<pad name="3.3V" x="-10.16" y="24.13" drill="0.8" shape="long" rot="R180"/>
<pad name="AREF" x="-10.16" y="21.59" drill="0.8" shape="long" rot="R180"/>
<pad name="5V" x="-10.16" y="-1.27" drill="0.8" shape="long"/>
<pad name="ICSP2" x="-5.08" y="-7.62" drill="0.8" rot="R90"/>
<pad name="ICSP4" x="-2.54" y="-7.62" drill="0.8" rot="R90"/>
<pad name="ICSP6" x="0" y="-7.62" drill="0.8" rot="R90"/>
<pad name="A4" x="-10.16" y="8.89" drill="0.8" shape="long" rot="R180"/>
<pad name="A5" x="-10.16" y="6.35" drill="0.8" shape="long" rot="R180"/>
<pad name="A6" x="-10.16" y="3.81" drill="0.8" shape="long" rot="R180"/>
<pad name="A7" x="-10.16" y="1.27" drill="0.8" shape="long" rot="R180"/>
<pad name="ICSP1" x="-5.08" y="-10.16" drill="0.8" rot="R90"/>
<pad name="ICSP3" x="-2.54" y="-10.16" drill="0.8" rot="R90"/>
<pad name="ICSP5" x="0" y="-10.16" drill="0.8" rot="R90"/>
</package>
<package name="NRF24-2X4">
<pad name="GND" x="-1.27" y="2.54" drill="0.8" shape="square"/>
<pad name="CE" x="-3.81" y="2.54" drill="0.8"/>
<pad name="SCK" x="-6.35" y="2.54" drill="0.8"/>
<pad name="MISO" x="-8.89" y="2.54" drill="0.8"/>
<pad name="IRQ" x="-8.89" y="0" drill="0.8"/>
<pad name="MOSI" x="-6.35" y="0" drill="0.8"/>
<pad name="CSN" x="-3.81" y="0" drill="0.8"/>
<pad name="VCC" x="-1.27" y="0" drill="0.8"/>
</package>
<package name="PRO-MINI">
<description>Arduino Pro Mini Clone</description>
<pad name="TX0" x="-6.35" y="26.67" drill="0.8" shape="long"/>
<pad name="RX1" x="-6.35" y="24.13" drill="0.8" shape="long"/>
<pad name="RST1" x="-6.35" y="21.59" drill="0.8" shape="long"/>
<pad name="GND1" x="-6.35" y="19.05" drill="0.8" shape="long"/>
<pad name="D2" x="-6.35" y="16.51" drill="0.8" shape="long"/>
<pad name="D3" x="-6.35" y="13.97" drill="0.8" shape="long"/>
<pad name="D4" x="-6.35" y="11.43" drill="0.8" shape="long"/>
<pad name="D5" x="-6.35" y="8.89" drill="0.8" shape="long"/>
<pad name="D6" x="-6.35" y="6.35" drill="0.8" shape="long"/>
<pad name="D7" x="-6.35" y="3.81" drill="0.8" shape="long"/>
<pad name="D8" x="-6.35" y="1.27" drill="0.8" shape="long"/>
<pad name="D9" x="-6.35" y="-1.27" drill="0.8" shape="long"/>
<pad name="RAW" x="8.89" y="26.67" drill="0.8" shape="long"/>
<pad name="GND" x="8.89" y="24.13" drill="0.8" shape="long"/>
<pad name="RST" x="8.89" y="21.59" drill="0.8" shape="long"/>
<pad name="VCC" x="8.89" y="19.05" drill="0.8" shape="long"/>
<pad name="A3" x="8.89" y="16.51" drill="0.8" shape="long"/>
<pad name="A2" x="8.89" y="13.97" drill="0.8" shape="long"/>
<pad name="A1" x="8.89" y="11.43" drill="0.8" shape="long"/>
<pad name="A0" x="8.89" y="8.89" drill="0.8" shape="long"/>
<pad name="D13" x="8.89" y="6.35" drill="0.8" shape="long"/>
<pad name="D12" x="8.89" y="3.81" drill="0.8" shape="long"/>
<pad name="D11" x="8.89" y="1.27" drill="0.8" shape="long"/>
<pad name="D10" x="8.89" y="-1.27" drill="0.8" shape="long"/>
<pad name="GND2" x="-5.08" y="29.21" drill="0.8" shape="long" rot="R90"/>
<pad name="GND3" x="-2.54" y="29.21" drill="0.8" shape="long" rot="R90"/>
<pad name="VCC1" x="0" y="29.21" drill="0.8" shape="long" rot="R90"/>
<pad name="RX1-1" x="2.54" y="29.21" drill="0.8" shape="long" rot="R90"/>
<pad name="TX0-1" x="5.08" y="29.21" drill="0.8" shape="long" rot="R90"/>
<pad name="DTR" x="7.62" y="29.21" drill="0.8" shape="long" rot="R90"/>
<pad name="A4" x="-2.54" y="-1.27" drill="0.8" shape="long" rot="R90"/>
<pad name="A5" x="0" y="-1.27" drill="0.8" shape="long" rot="R90"/>
<pad name="A6" x="2.54" y="-1.27" drill="0.8" shape="long" rot="R90"/>
<pad name="A7" x="5.08" y="-1.27" drill="0.8" shape="long" rot="R90"/>
</package>
</packages>
<symbols>
<symbol name="NANO">
<pin name="3.3V" x="-22.86" y="12.7" visible="pin" length="middle"/>
<pin name="AREF" x="-22.86" y="10.16" visible="pin" length="middle"/>
<pin name="ICSP1" x="-10.16" y="-27.94" visible="off" length="point" rot="R270"/>
<pin name="ICSP2" x="-10.16" y="-25.4" visible="off" length="point" rot="R270"/>
<pin name="ICSP3" x="-7.62" y="-27.94" visible="off" length="point" rot="R270"/>
<pin name="ICSP4" x="-7.62" y="-25.4" visible="off" length="point" rot="R270"/>
<pin name="TX0" x="10.16" y="-20.32" visible="pin" length="middle" rot="R180"/>
<pin name="RX1" x="10.16" y="-17.78" visible="pin" length="middle" rot="R180"/>
<pin name="RST1" x="10.16" y="-15.24" visible="pin" length="middle" rot="R180"/>
<pin name="GND2" x="10.16" y="-12.7" visible="pin" length="middle" rot="R180"/>
<pin name="D2" x="10.16" y="-10.16" visible="pin" length="middle" rot="R180"/>
<pin name="D3" x="10.16" y="-7.62" visible="pin" length="middle" rot="R180"/>
<pin name="D4" x="10.16" y="-5.08" visible="pin" length="middle" rot="R180"/>
<pin name="D5" x="10.16" y="-2.54" visible="pin" length="middle" rot="R180"/>
<pin name="D6" x="10.16" y="0" visible="pin" length="middle" rot="R180"/>
<pin name="D7" x="10.16" y="2.54" visible="pin" length="middle" rot="R180"/>
<pin name="D8" x="10.16" y="5.08" visible="pin" length="middle" rot="R180"/>
<pin name="D9" x="10.16" y="7.62" visible="pin" length="middle" rot="R180"/>
<pin name="RAW" x="-22.86" y="-20.32" visible="pin" length="middle"/>
<pin name="GND" x="-22.86" y="-17.78" visible="pin" length="middle"/>
<pin name="RST" x="-22.86" y="-15.24" visible="pin" length="middle"/>
<pin name="5.5V" x="-22.86" y="-12.7" visible="pin" length="middle"/>
<pin name="A3" x="-22.86" y="0" visible="pin" length="middle"/>
<pin name="A2" x="-22.86" y="2.54" visible="pin" length="middle"/>
<pin name="A1" x="-22.86" y="5.08" visible="pin" length="middle"/>
<pin name="A0" x="-22.86" y="7.62" visible="pin" length="middle"/>
<pin name="D13" x="-22.86" y="15.24" visible="pin" length="middle"/>
<pin name="D12" x="10.16" y="15.24" visible="pin" length="middle" rot="R180"/>
<pin name="D11" x="10.16" y="12.7" visible="pin" length="middle" rot="R180"/>
<pin name="D10" x="10.16" y="10.16" visible="pin" length="middle" rot="R180"/>
<pin name="A7" x="-22.86" y="-10.16" visible="pin" length="middle"/>
<pin name="A6" x="-22.86" y="-7.62" visible="pin" length="middle"/>
<pin name="A5" x="-22.86" y="-5.08" visible="pin" length="middle"/>
<pin name="A4" x="-22.86" y="-2.54" visible="pin" length="middle"/>
<pin name="ICSP5" x="-5.08" y="-27.94" visible="off" length="point" rot="R270"/>
<pin name="ICSP6" x="-5.08" y="-25.4" visible="off" length="point" rot="R270"/>
<wire x1="-17.78" y1="17.78" x2="-17.78" y2="-30.48" width="0.254" layer="94"/>
<wire x1="-17.78" y1="-30.48" x2="5.08" y2="-30.48" width="0.254" layer="94"/>
<wire x1="5.08" y1="-30.48" x2="5.08" y2="17.78" width="0.254" layer="94"/>
<wire x1="5.08" y1="17.78" x2="-17.78" y2="17.78" width="0.254" layer="94"/>
<text x="-12.7" y="20.32" size="1.778" layer="95">Arduino Nano</text>
</symbol>
<symbol name="NRF24-2X4">
<wire x1="-5.08" y1="3.81" x2="8.89" y2="3.81" width="0.4064" layer="94"/>
<wire x1="8.89" y1="3.81" x2="8.89" y2="1.27" width="0.4064" layer="94"/>
<wire x1="8.89" y1="1.27" x2="8.89" y2="-1.27" width="0.4064" layer="94"/>
<wire x1="8.89" y1="-1.27" x2="8.89" y2="-17.78" width="0.4064" layer="94"/>
<wire x1="8.89" y1="-17.78" x2="-5.08" y2="-17.78" width="0.4064" layer="94"/>
<wire x1="-5.08" y1="-17.78" x2="-5.08" y2="-10.414" width="0.4064" layer="94"/>
<wire x1="-5.08" y1="-10.414" x2="-5.08" y2="-2.794" width="0.4064" layer="94"/>
<wire x1="-5.08" y1="-2.794" x2="-5.08" y2="3.81" width="0.4064" layer="94"/>
<wire x1="8.89" y1="1.27" x2="6.35" y2="1.27" width="0.254" layer="94"/>
<wire x1="6.35" y1="1.27" x2="6.35" y2="-1.27" width="0.254" layer="94"/>
<wire x1="6.35" y1="-1.27" x2="8.89" y2="-1.27" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-2.794" x2="-1.016" y2="-2.54" width="0.254" layer="94" curve="-180"/>
<wire x1="-1.016" y1="-10.16" x2="-5.08" y2="-10.414" width="0.254" layer="94" curve="-180"/>
<wire x1="-1.016" y1="-10.16" x2="-1.016" y2="-2.54" width="0.254" layer="94"/>
<wire x1="5.08" y1="-11.43" x2="5.08" y2="-12.7" width="0.254" layer="94"/>
<wire x1="5.08" y1="-12.7" x2="5.08" y2="-17.018" width="0.254" layer="94"/>
<wire x1="5.08" y1="-17.018" x2="3.81" y2="-17.018" width="0.254" layer="94"/>
<wire x1="3.81" y1="-17.018" x2="3.81" y2="-13.97" width="0.254" layer="94"/>
<wire x1="3.81" y1="-13.97" x2="2.54" y2="-13.97" width="0.254" layer="94"/>
<wire x1="2.54" y1="-13.97" x2="2.54" y2="-17.018" width="0.254" layer="94"/>
<wire x1="2.54" y1="-17.018" x2="1.27" y2="-17.018" width="0.254" layer="94"/>
<wire x1="1.27" y1="-17.018" x2="1.27" y2="-13.97" width="0.254" layer="94"/>
<wire x1="1.27" y1="-13.97" x2="0" y2="-13.97" width="0.254" layer="94"/>
<wire x1="0" y1="-13.97" x2="0" y2="-17.018" width="0.254" layer="94"/>
<wire x1="0" y1="-17.018" x2="-1.27" y2="-17.018" width="0.254" layer="94"/>
<wire x1="-1.27" y1="-17.018" x2="-1.27" y2="-13.97" width="0.254" layer="94"/>
<wire x1="-1.27" y1="-13.97" x2="-2.54" y2="-13.97" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-13.97" x2="-2.54" y2="-17.018" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-17.018" x2="-4.318" y2="-17.018" width="0.254" layer="94"/>
<wire x1="5.08" y1="-12.7" x2="0" y2="-12.7" width="0.254" layer="94"/>
<pin name="GND" x="7.62" y="0" visible="pin" length="point" rot="R270"/>
<pin name="CSN" x="5.08" y="0" visible="pin" length="point" rot="R270"/>
<pin name="MOSI" x="2.54" y="0" visible="pin" length="point" rot="R270"/>
<pin name="IRQ" x="0" y="0" visible="pin" length="point" rot="R270"/>
<pin name="MISO" x="0" y="2.54" length="point" rot="R90"/>
<pin name="SCK" x="2.54" y="2.54" length="point" rot="R90"/>
<pin name="CE" x="5.08" y="2.54" length="point" rot="R90"/>
<pin name="VCC" x="7.62" y="2.54" length="point" rot="R90"/>
</symbol>
<symbol name="PRO-MINI">
<description>Arduino Pro Mini Clone</description>
<pin name="TX0" x="-22.86" y="20.32" visible="pin" length="middle"/>
<pin name="RX1" x="-22.86" y="17.78" visible="pin" length="middle"/>
<pin name="RST2" x="-22.86" y="15.24" visible="pin" length="middle"/>
<pin name="GND2" x="-22.86" y="12.7" visible="pin" length="middle"/>
<pin name="D2" x="-22.86" y="10.16" visible="pin" length="middle"/>
<pin name="D3" x="-22.86" y="7.62" visible="pin" length="middle"/>
<pin name="D4" x="-22.86" y="5.08" visible="pin" length="middle"/>
<pin name="D5" x="-22.86" y="2.54" visible="pin" length="middle"/>
<pin name="D6" x="-22.86" y="0" visible="pin" length="middle"/>
<pin name="D7" x="-22.86" y="-2.54" visible="pin" length="middle"/>
<pin name="D8" x="-22.86" y="-5.08" visible="pin" length="middle"/>
<pin name="D9" x="-22.86" y="-7.62" visible="pin" length="middle"/>
<pin name="RAW" x="17.78" y="20.32" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="GND" x="17.78" y="17.78" visible="pin" length="middle" direction="in" rot="R180"/>
<pin name="RST" x="17.78" y="15.24" visible="pin" length="middle" rot="R180"/>
<pin name="VCC" x="17.78" y="12.7" visible="pin" length="middle" rot="R180"/>
<pin name="A3" x="17.78" y="10.16" visible="pin" length="middle" rot="R180"/>
<pin name="A2" x="17.78" y="7.62" visible="pin" length="middle" rot="R180"/>
<pin name="A1" x="17.78" y="5.08" visible="pin" length="middle" rot="R180"/>
<pin name="A0" x="17.78" y="2.54" visible="pin" length="middle" rot="R180"/>
<pin name="D13" x="17.78" y="0" visible="pin" length="middle" rot="R180"/>
<pin name="D12" x="17.78" y="-2.54" visible="pin" length="middle" rot="R180"/>
<pin name="D11" x="17.78" y="-5.08" visible="pin" length="middle" rot="R180"/>
<pin name="D10" x="17.78" y="-7.62" visible="pin" length="middle" rot="R180"/>
<pin name="GND4" x="-7.62" y="35.56" visible="pin" length="middle" rot="R270"/>
<pin name="GND3" x="-5.08" y="35.56" visible="pin" length="middle" rot="R270"/>
<pin name="VCC2" x="-2.54" y="35.56" visible="pin" length="middle" rot="R270"/>
<pin name="RX1-1" x="0" y="35.56" visible="pin" length="middle" rot="R270"/>
<pin name="TX0-1" x="2.54" y="35.56" visible="pin" length="middle" rot="R270"/>
<pin name="DTR" x="5.08" y="35.56" visible="pin" length="middle" rot="R270"/>
<pin name="A4" x="-5.08" y="-17.78" visible="pin" length="middle" rot="R90"/>
<pin name="A5" x="-2.54" y="-17.78" visible="pin" length="middle" rot="R90"/>
<pin name="A6" x="0" y="-17.78" visible="pin" length="middle" rot="R90"/>
<pin name="A7" x="2.54" y="-17.78" visible="pin" length="middle" rot="R90"/>
<wire x1="-17.78" y1="30.48" x2="12.7" y2="30.48" width="0.254" layer="94"/>
<wire x1="12.7" y1="30.48" x2="12.7" y2="-12.7" width="0.254" layer="94"/>
<wire x1="12.7" y1="-12.7" x2="-17.78" y2="-12.7" width="0.254" layer="94"/>
<wire x1="-17.78" y1="-12.7" x2="-17.78" y2="30.48" width="0.254" layer="94"/>
<text x="-2.54" y="0" size="1.778" layer="95" rot="R90">Arduino Pro Mini</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="NANO">
<description>Arduino Nano</description>
<gates>
<gate name="G$1" symbol="NANO" x="7.62" y="2.54"/>
</gates>
<devices>
<device name="" package="NANO">
<connects>
<connect gate="G$1" pin="3.3V" pad="3.3V"/>
<connect gate="G$1" pin="5.5V" pad="5V"/>
<connect gate="G$1" pin="A0" pad="A0"/>
<connect gate="G$1" pin="A1" pad="A1"/>
<connect gate="G$1" pin="A2" pad="A2"/>
<connect gate="G$1" pin="A3" pad="A3"/>
<connect gate="G$1" pin="A4" pad="A4"/>
<connect gate="G$1" pin="A5" pad="A5"/>
<connect gate="G$1" pin="A6" pad="A6"/>
<connect gate="G$1" pin="A7" pad="A7"/>
<connect gate="G$1" pin="AREF" pad="AREF"/>
<connect gate="G$1" pin="D10" pad="D10"/>
<connect gate="G$1" pin="D11" pad="D11"/>
<connect gate="G$1" pin="D12" pad="D12"/>
<connect gate="G$1" pin="D13" pad="D13"/>
<connect gate="G$1" pin="D2" pad="D2"/>
<connect gate="G$1" pin="D3" pad="D3"/>
<connect gate="G$1" pin="D4" pad="D4"/>
<connect gate="G$1" pin="D5" pad="D5"/>
<connect gate="G$1" pin="D6" pad="D6"/>
<connect gate="G$1" pin="D7" pad="D7"/>
<connect gate="G$1" pin="D8" pad="D8"/>
<connect gate="G$1" pin="D9" pad="D9"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="GND2" pad="GND1"/>
<connect gate="G$1" pin="ICSP1" pad="ICSP1"/>
<connect gate="G$1" pin="ICSP2" pad="ICSP2"/>
<connect gate="G$1" pin="ICSP3" pad="ICSP3"/>
<connect gate="G$1" pin="ICSP4" pad="ICSP4"/>
<connect gate="G$1" pin="ICSP5" pad="ICSP5"/>
<connect gate="G$1" pin="ICSP6" pad="ICSP6"/>
<connect gate="G$1" pin="RAW" pad="RAW"/>
<connect gate="G$1" pin="RST" pad="RST"/>
<connect gate="G$1" pin="RST1" pad="RST1"/>
<connect gate="G$1" pin="RX1" pad="RX1"/>
<connect gate="G$1" pin="TX0" pad="TX0"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="NRF24">
<gates>
<gate name="G$1" symbol="NRF24-2X4" x="-2.54" y="7.62"/>
</gates>
<devices>
<device name="" package="NRF24-2X4">
<connects>
<connect gate="G$1" pin="CE" pad="CE"/>
<connect gate="G$1" pin="CSN" pad="CSN"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="IRQ" pad="IRQ"/>
<connect gate="G$1" pin="MISO" pad="MISO"/>
<connect gate="G$1" pin="MOSI" pad="MOSI"/>
<connect gate="G$1" pin="SCK" pad="SCK"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="PRO-MINI">
<description>Arduion Pro Mini Clone V1.0
www.betemcu.cu</description>
<gates>
<gate name="G$1" symbol="PRO-MINI" x="38.1" y="-5.08"/>
</gates>
<devices>
<device name="" package="PRO-MINI">
<connects>
<connect gate="G$1" pin="A0" pad="A0"/>
<connect gate="G$1" pin="A1" pad="A1"/>
<connect gate="G$1" pin="A2" pad="A2"/>
<connect gate="G$1" pin="A3" pad="A3"/>
<connect gate="G$1" pin="A4" pad="A4"/>
<connect gate="G$1" pin="A5" pad="A5"/>
<connect gate="G$1" pin="A6" pad="A6"/>
<connect gate="G$1" pin="A7" pad="A7"/>
<connect gate="G$1" pin="D10" pad="D10"/>
<connect gate="G$1" pin="D11" pad="D11"/>
<connect gate="G$1" pin="D12" pad="D12"/>
<connect gate="G$1" pin="D13" pad="D13"/>
<connect gate="G$1" pin="D2" pad="D2"/>
<connect gate="G$1" pin="D3" pad="D3"/>
<connect gate="G$1" pin="D4" pad="D4"/>
<connect gate="G$1" pin="D5" pad="D5"/>
<connect gate="G$1" pin="D6" pad="D6"/>
<connect gate="G$1" pin="D7" pad="D7"/>
<connect gate="G$1" pin="D8" pad="D8"/>
<connect gate="G$1" pin="D9" pad="D9"/>
<connect gate="G$1" pin="DTR" pad="DTR"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="GND2" pad="GND1"/>
<connect gate="G$1" pin="GND3" pad="GND3"/>
<connect gate="G$1" pin="GND4" pad="GND2"/>
<connect gate="G$1" pin="RAW" pad="RAW"/>
<connect gate="G$1" pin="RST" pad="RST"/>
<connect gate="G$1" pin="RST2" pad="RST1"/>
<connect gate="G$1" pin="RX1" pad="RX1"/>
<connect gate="G$1" pin="RX1-1" pad="RX1-1"/>
<connect gate="G$1" pin="TX0" pad="TX0"/>
<connect gate="G$1" pin="TX0-1" pad="TX0-1"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
<connect gate="G$1" pin="VCC2" pad="VCC1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$1" library="Arduino-clone" deviceset="NANO" device=""/>
<part name="U$2" library="Arduino-clone" deviceset="NRF24" device=""/>
<part name="U$3" library="Arduino-clone" deviceset="PRO-MINI" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="60.96" y="50.8"/>
<instance part="U$2" gate="G$1" x="95.25" y="60.96"/>
<instance part="U$3" gate="G$1" x="7.62" y="58.42" rot="R180"/>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
