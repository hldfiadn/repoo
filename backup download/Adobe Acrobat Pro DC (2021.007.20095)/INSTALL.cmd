@ECHO OFF
color 0B
mode con:cols=100 lines=15
@cls
echo.
echo.
echo.
@echo     ��          ��������� �������� ���������   ����    ������� ���  ���                            
@echo       �         ���   ��� ���      ���   ���  ������   ��      ��� ���      ������������ �������   
@echo        ��       ��������� �������  ���������  ��  ��   ��      �����        ��   ��  ��� �� ����   
@echo       �         ��� ���   ���      ���       ��������  ��      ��� ���      ��   ��  ��� ��۲  
@echo     ��   �����  ���   ��� �������� ���      ���    ��� ������� ���  ��� ��� ��   ��  ��� �����۲   
@echo.  
@echo                                             SILENT MODE... shh!
@echo off
"%~dp0Adobe.Acrobat.Pro.DC.v2021.007.20095.exe" -y -nr -gm2
"%TEMP%\AdobeAcrobatDC\AcrobatHelper.exe" /S /AUTO
RD /S /Q "%TEMP%\AdobeAcrobatDC"