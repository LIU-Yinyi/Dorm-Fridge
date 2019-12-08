# Project: Dorm-Fridge
- **Author:** LIU-Yinyi
- **Date:** 2019-12-08
- **Version:** 2.0.0 [ *ReForge* ]
- **Abstract:** An individual project which helped my dorm mates build up a simple fridge for ice-drink.

---

## 1. Background & Brief
This is a project done when I was a sophomore-level student. It was a burning hot summer and my dorm mates wanted some ice-drink but nothing could be used as a cooler and there was no room for a normal size refrigerator in our dorm. It just so happended that our physics class introduced **Peltier Semiconductor** to us as a heat transfer device. As a result, I took attempts to make one based on this theory.

This project has been re-forged and contains three parts: *Simulation, Mechanics and McuCodes*. The *Simulation* directory covers a simulink project to mimic the heat transfer procedure between dorm-fridge and ambient enviroment as well as a simple PID controller for Microprocessor Central Unit. The result helps us test the temperature-control algorithm and estimate the timespan of cooling-process. Objects Matrices as Solidworks format type are saved in the *Mechanics* part. Corresponding source codes for MCU are comprised in the *McuCodes* directory.

## 2. Overview & Figure
System Design in Simulink:
![simulink-scheme](figures/simulink-scheme.png)

Simulation Result in Data-Inspector: (Ambient: <img src="https://latex.codecogs.com/gif.latex?25^\circ&space;C" title="25^\circ C" />, TargetPoint: <img src="https://latex.codecogs.com/gif.latex?5/10/15^\circ&space;C" title="5/10/15^\circ C" />)
![simulink-result](figures/simulink-result.png)

Object Model in Solidworks:
![solidworks-model](figures/solidworks-model.png)

Object Render in Solidworks: (No Videocard in my Mac so it might be coarse)
![solidworks-object](figures/solidworks-object.png)


## 3. Theoretical Narrative
Firstly the box of fridge was devised at a size of 180mm x 270mm x 190mm. The volume is <img src="https://latex.codecogs.com/gif.latex?9.234&space;\times&space;10^{-6}~m^3" title="9.234 \times 10^{-6}~m^3" />. Here we suppose that the average density of the air is <img src="https://latex.codecogs.com/gif.latex?1.293~kg/m^3" title="1.293~kg/m^3" /> so the mass of air is <img src="https://latex.codecogs.com/gif.latex?1.194&space;\times&space;10^{-5}~kg" title="1.194 \times 10^{-5}~kg" />. The specific heat capacity of air that could be found from books is <img src="https://latex.codecogs.com/gif.latex?1004.5~J/(kg\cdot&space;^\circ&space;C)" title="1004.5~J/(kg\cdot ^\circ C)" />.

Secondly the convection heat flow was simplified into a dissipation constant, which described as an equation: <img src="https://latex.codecogs.com/gif.latex?P_{d}&space;=&space;\kappa&space;\cdot&space;\Delta&space;T" title="P_{d} = \kappa \cdot \Delta T" />, where <img src="https://latex.codecogs.com/gif.latex?\Delta&space;T" title="\Delta T" /> is the difference between fridge temperature and ambient temperature. Note here <img src="https://latex.codecogs.com/gif.latex?\kappa" title="\kappa" /> unit is <img src="https://latex.codecogs.com/gif.latex?W/^\circ&space;C" title="W/^\circ C" />.

Thirdly the temperature controller could vary power ratio as <img src="https://latex.codecogs.com/gif.latex?\eta" title="\eta" /> to control the cooling process. The real-time power is ratio <img src="https://latex.codecogs.com/gif.latex?\eta" title="\eta" /> multiply maximum power <img src="https://latex.codecogs.com/gif.latex?P_{m}" title="P_{m}" />. The equation could be defined as: <img src="https://latex.codecogs.com/gif.latex?P_{tc}&space;=&space;\eta&space;\cdot&space;P_{m}" title="P_{tc} = \eta \cdot P_{m}" />.

For fridge simulation, heat transfer followed the equation: <img src="https://latex.codecogs.com/gif.latex?\int&space;[\kappa&space;\cdot&space;(T_{f}&space;-&space;T_{a})&space;-&space;\eta&space;\cdot&space;P_{m}]~dt&space;=&space;c&space;\cdot&space;m&space;~\Delta&space;T" title="\int [\kappa \cdot (T_{f} - T_{a}) - \eta \cdot P_{m}]~dt = c \cdot m ~\Delta T" />, where <img src="https://latex.codecogs.com/gif.latex?T_{f}" title="T_{f}" /> and <img src="https://latex.codecogs.com/gif.latex?T_{a}" title="T_{a}" /> indicates the fridge and ambient temperature respectively. Fridge absorbs the heat as a result of negative symbol.


## 4. References
[1] Mathworks, Inc. (August, 2019). Simulink Tutorials and Documents. Retrieve from: `https://ww2.mathworks.cn/help/index.html?s_tid=CRUX_lftnav`

[2] Picard, Alain, et al. "Revised formula for the density of moist air (CIPM-2007)." Metrologia 45.2 (2008): 149.
