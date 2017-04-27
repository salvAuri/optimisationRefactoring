// Created on: 2000-04-18
// Created by: Andrey BETENEV
// Copyright (c) 2000-2014 OPEN CASCADE SAS
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

// Generator:	ExpToCas (EXPRESS -> CASCADE/XSTEP Translator) V1.0

#include <Standard_Type.hxx>
#include <StepShape_ShapeDimensionRepresentation.hxx>

//=======================================================================
//function : StepShape_ShapeDimensionRepresentation
//purpose  : 
//=======================================================================
StepShape_ShapeDimensionRepresentation::StepShape_ShapeDimensionRepresentation ()
{
}

//=======================================================================
//function : Init
//purpose  : 
//=======================================================================
void StepShape_ShapeDimensionRepresentation::Init (const Handle(TCollection_HAsciiString)& theName, 
                                                   const Handle(StepRepr_HArray1OfRepresentationItem)& theItems, 
                                                   const Handle(StepRepr_RepresentationContext)& theContextOfItems)
{
  StepRepr_Representation::Init(theName, theItems, theContextOfItems);
}

//=======================================================================
//function : Init
//purpose  : 
//=======================================================================

void StepShape_ShapeDimensionRepresentation::Init (const Handle(TCollection_HAsciiString)& theName, 
                                                   const Handle(StepShape_HArray1OfShapeDimensionRepresentationItem)& theItems, 
                                                   const Handle(StepRepr_RepresentationContext)& theContextOfItems)
{
  StepRepr_Representation::Init(theName, NULL, theContextOfItems);
  itemsAP242 = theItems;
}

//=======================================================================
//function : Init
//purpose  : 
//=======================================================================

void StepShape_ShapeDimensionRepresentation::SetItemsAP242 (const Handle(StepShape_HArray1OfShapeDimensionRepresentationItem)& theItems)
{
  itemsAP242 = theItems;
}

//=======================================================================
//function : Init
//purpose  : 
//=======================================================================
  
Handle(StepShape_HArray1OfShapeDimensionRepresentationItem) StepShape_ShapeDimensionRepresentation::ItemsAP242() const
{
  return itemsAP242;
}