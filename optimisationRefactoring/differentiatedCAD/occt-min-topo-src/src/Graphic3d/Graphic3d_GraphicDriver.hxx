// Created on: 1997-01-28
// Created by: CAL
// Copyright (c) 1997-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#ifndef _Graphic3d_GraphicDriver_HeaderFile
#define _Graphic3d_GraphicDriver_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Standard_Integer.hxx>
#include <Aspect_DisplayConnection.hxx>
#include <Standard_Boolean.hxx>
#include <MMgt_TShared.hxx>
#include <Graphic3d_CView.hxx>
#include <Graphic3d_CStructure.hxx>
#include <Aspect_GradientFillMethod.hxx>
#include <Standard_CString.hxx>
#include <Aspect_FillMethod.hxx>
#include <Standard_Size.hxx>
#include <Quantity_NameOfColor.hxx>
#include <Standard_Real.hxx>
#include <Aspect_TypeOfTriedronPosition.hxx>
#include <Aspect_TypeOfTriedronEcho.hxx>
#include <Graphic3d_GraduatedTrihedron.hxx>
#include <Graphic3d_Vec3.hxx>
#include <Standard_ShortReal.hxx>
#include <Standard_Address.hxx>
#include <Graphic3d_PtrFrameBuffer.hxx>
#include <Image_PixMap.hxx>
#include <Graphic3d_BufferType.hxx>
#include <Aspect_Handle.hxx>
#include <Aspect_PrintAlgo.hxx>
#include <Graphic3d_ExportFormat.hxx>
#include <Graphic3d_SortType.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <Graphic3d_ZLayerSettings.hxx>
#include <Graphic3d_CLight.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <TColStd_SequenceOfInteger.hxx>

class Graphic3d_CView;
class Graphic3d_GraphicDriver;
class Graphic3d_TransformError;
class Graphic3d_Structure;
class Graphic3d_StructureManager;
class Graphic3d_ViewManager;
class Quantity_Color;
class TCollection_AsciiString;

DEFINE_STANDARD_HANDLE(Graphic3d_GraphicDriver, MMgt_TShared)

//! This class allows the definition of a graphic driver
//! for 3d interface (currently only OpenGl driver is used).
class Graphic3d_GraphicDriver : public MMgt_TShared
{

public:

  
  //! call_togl_inquirelight
  virtual Standard_Integer InquireLightLimit() = 0;
  
  //! call_togl_inquireplane
  virtual Standard_Integer InquirePlaneLimit() = 0;
  
  //! call_togl_inquireview
  virtual Standard_Integer InquireViewLimit() = 0;
  
  //! Creates new empty graphic structure
  virtual Handle(Graphic3d_CStructure) CreateStructure (const Handle(Graphic3d_StructureManager)& theManager) = 0;
  
  //! Removes structure from graphic driver and releases its resources.
  virtual void RemoveStructure (Handle(Graphic3d_CStructure)& theCStructure) = 0;
  
  //! Creates new view for this graphic driver.
  virtual Handle(Graphic3d_CView) CreateView (const Handle(Graphic3d_StructureManager)& theMgr) = 0;
  
  //! Removes view from graphic driver and releases its resources.
  virtual void RemoveView (const Handle(Graphic3d_CView)& theView) = 0;

  //! enables/disables usage of OpenGL vertex buffer arrays while drawing primitiev arrays
  virtual void EnableVBO (const Standard_Boolean status) = 0;
  
  //! Returns information about GPU memory usage.
  virtual Standard_Boolean MemoryInfo (Standard_Size& theFreeBytes, TCollection_AsciiString& theInfo) const = 0;
  
  virtual Standard_ShortReal DefaultTextHeight() const = 0;
  
  //! Computes text width.
  virtual void TextSize (const Handle(Graphic3d_CView)& theView,
                         const Standard_CString         theText,
                         const Standard_ShortReal       theHeight,
                         Standard_ShortReal&            theWidth,
                         Standard_ShortReal&            theAscent,
                         Standard_ShortReal&            theDescent) const = 0;

  //! Add a new top-level z layer with ID <theLayerId> for
  //! the view. Z layers allow drawing structures in higher layers
  //! in foreground of structures in lower layers. To add a structure
  //! to desired layer on display it is necessary to set the layer
  //! ID for the structure.
  virtual void AddZLayer (const Graphic3d_ZLayerId theLayerId) = 0;

  //! Removes Z layer. All structures displayed at the moment in layer will be displayed in
  //! default layer (the bottom-level z layer). By default, there are always default
  //! bottom-level layer that can't be removed.  The passed theLayerId should be not less than 0
  //! (reserved for default layers that can not be removed).
  virtual void RemoveZLayer (const Graphic3d_ZLayerId theLayerId) = 0;

  //! Returns list of Z layers defined for the graphical driver.
  virtual void ZLayers (TColStd_SequenceOfInteger& theLayerSeq) const = 0;

  //! Sets the settings for a single Z layer.
  virtual void SetZLayerSettings (const Graphic3d_ZLayerId theLayerId, const Graphic3d_ZLayerSettings& theSettings) = 0;

  //! Returns the settings of a single Z layer.
  virtual Graphic3d_ZLayerSettings ZLayerSettings (const Graphic3d_ZLayerId theLayerId) = 0;

  //! Returns view associated with the window if it is exists and is activated.
  //! Returns Standard_True if the view associated to the window exists.
  virtual Standard_Boolean ViewExists (const Handle(Aspect_Window)& theWindow, Handle(Graphic3d_CView)& theView) = 0;

  Standard_EXPORT void PrintBoolean (const Standard_CString AComment, const Standard_Boolean AValue) const;
  
  Standard_EXPORT void PrintCLight (const Graphic3d_CLight& ACLight, const Standard_Integer AField) const;

  Standard_EXPORT void PrintCStructure (const Graphic3d_CStructure& ACStructure, const Standard_Integer AField) const;
  
  Standard_EXPORT void PrintCView (const Graphic3d_CView& ACView, const Standard_Integer AField) const;
  
  Standard_EXPORT void PrintFunction (const Standard_CString AFunc) const;
  
  Standard_EXPORT void PrintInteger (const Standard_CString AComment, const Standard_Integer AValue) const;
  
  Standard_EXPORT void PrintIResult (const Standard_CString AFunc, const Standard_Integer AResult) const;
  
  Standard_EXPORT void PrintShortReal (const Standard_CString AComment, const Standard_ShortReal AValue) const;
  
  Standard_EXPORT void PrintMatrix (const Standard_CString AComment, const TColStd_Array2OfReal& AMatrix) const;
  
  Standard_EXPORT void PrintString (const Standard_CString AComment, const Standard_CString AString) const;
  
  Standard_EXPORT void SetTrace (const Standard_Integer ALevel);
  
  Standard_EXPORT Standard_Integer Trace() const;
  
  //! returns Handle to display connection
  Standard_EXPORT const Handle(Aspect_DisplayConnection)& GetDisplayConnection() const;
  
  Standard_EXPORT Standard_Boolean IsDeviceLost() const;
  
  Standard_EXPORT void ResetDeviceLostFlag();

  DEFINE_STANDARD_RTTI(Graphic3d_GraphicDriver,MMgt_TShared)

protected:

  
  //! Initializes the Driver
  Standard_EXPORT Graphic3d_GraphicDriver(const Handle(Aspect_DisplayConnection)& theDisp);

  Standard_Integer MyTraceLevel;
  Handle(Aspect_DisplayConnection) myDisplayConnection;
  Standard_Boolean myDeviceLostFlag;


private:




};







#endif // _Graphic3d_GraphicDriver_HeaderFile