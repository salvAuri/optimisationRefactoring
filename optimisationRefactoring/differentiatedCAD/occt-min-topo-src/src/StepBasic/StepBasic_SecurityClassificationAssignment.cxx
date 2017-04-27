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


#include <Standard_Type.hxx>
#include <StepBasic_SecurityClassification.hxx>
#include <StepBasic_SecurityClassificationAssignment.hxx>

void StepBasic_SecurityClassificationAssignment::Init(
	const Handle(StepBasic_SecurityClassification)& aAssignedSecurityClassification)
{
	// --- classe own fields ---
	assignedSecurityClassification = aAssignedSecurityClassification;
}


void StepBasic_SecurityClassificationAssignment::SetAssignedSecurityClassification(const Handle(StepBasic_SecurityClassification)& aAssignedSecurityClassification)
{
	assignedSecurityClassification = aAssignedSecurityClassification;
}

Handle(StepBasic_SecurityClassification) StepBasic_SecurityClassificationAssignment::AssignedSecurityClassification() const
{
	return assignedSecurityClassification;
}