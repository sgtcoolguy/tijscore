/**
 * Appcelerator Titanium License
 * This source code and all modifications done by Appcelerator
 * are licensed under the Apache Public License (version 2) and
 * are Copyright (c) 2009-2014 by Appcelerator, Inc.
 */

/*
 * Copyright (C) 2013 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#ifndef ProfiledCodeBlockJettisoningWatchpoint_h
#define ProfiledCodeBlockJettisoningWatchpoint_h

#include "CodeOrigin.h"
#include "ExitKind.h"
#include "Watchpoint.h"

namespace TI {

class CodeBlock;

class ProfiledCodeBlockJettisoningWatchpoint : public Watchpoint {
public:
    ProfiledCodeBlockJettisoningWatchpoint()
        : m_exitKind(ExitKindUnset)
        , m_codeBlock(0)
    {
    }
    
    ProfiledCodeBlockJettisoningWatchpoint(
        CodeOrigin codeOrigin, ExitKind exitKind, CodeBlock* codeBlock)
        : m_codeOrigin(codeOrigin)
        , m_exitKind(exitKind)
        , m_codeBlock(codeBlock)
    {
    }
    
protected:
    virtual void fireInternal() OVERRIDE;

private:
    CodeOrigin m_codeOrigin;
    ExitKind m_exitKind;
    CodeBlock* m_codeBlock;
};

} // namespace TI

#endif // ProfiledCodeBlockJettisoningWatchpoint_h

