setenv SIM_WORKING_FOLDER .
set newDesign 0
if {![file exists "C:/Users/Joseph Martin/EncCount/Sim/Sim.adf"]} { 
	design create Sim "C:/Users/Joseph Martin/EncCount"
  set newDesign 1
}
design open "C:/Users/Joseph Martin/EncCount/Sim"
cd "C:/Users/Joseph Martin/EncCount"
designverincludedir -clear
designverlibrarysim -PL -clear
designverlibrarysim -L -clear
designverlibrarysim -PL pmi_work
designverlibrarysim ovi_machxo2
designverdefinemacro -clear
if {$newDesign == 0} { 
  removefile -Y -D *
}
addfile "C:/Users/Joseph Martin/EncCount/blink.vhd"
addfile "C:/Users/Joseph Martin/EncCount/i2c.vhd"
addfile "C:/Users/Joseph Martin/EncCount/decoder.vhd"
vlib "C:/Users/Joseph Martin/EncCount/Sim/work"
set worklib work
adel -all
vcom -dbg -work work "C:/Users/Joseph Martin/EncCount/blink.vhd"
vcom -dbg -work work "C:/Users/Joseph Martin/EncCount/i2c.vhd"
vcom -dbg -work work "C:/Users/Joseph Martin/EncCount/decoder.vhd"
entity blink
vsim  +access +r blink   -PL pmi_work -L ovi_machxo2
add wave *
run 1000ns
