% JGB37-3530 DC Motor Transfer Function
clear all; close all; clc;

%--- 1. Approximate Motor Parameters (Needs verification) ---
R = 7.5;        % Armature Resistance (Ohm)
L = 0.5e-3;     % Armature Inductance (H)
Kt = 0.05;      % Torque Constant (N.m/A)
Ke = 0.05;      % Back EMF Constant (V.s/rad)
J = 1e-5;       % Rotor Moment of Inertia (kg.m^2)
b = 1e-6;       % Viscous Friction Coefficient (N.m.s)

%--- 2. Create Transfer Function ---
% P(s) = Kt / ( (L*s + R)*(J*s + b) + Kt*Ke )
num = [Kt];
den = [(L*J) (L*b + R*J) (R*b + Kt*Ke)];

motor_tf = tf(num, den)

%--- 3. Analyze System ---
% Plot Step Response (Speed vs Voltage)
figure;
step(motor_tf);
title('Step Response of JGB37-3530 Speed');
grid on;

% Bode Plot
figure;
bode(motor_tf);
title('Bode Plot of JGB37-3530');
grid on;
