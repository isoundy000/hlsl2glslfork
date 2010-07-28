//
//Copyright (C) 2005-2006  ATI Research, Inc.
//All rights reserved.
//
//Redistribution and use in source and binary forms, with or without
//modification, are permitted provided that the following conditions
//are met:
//
//    Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
//    Redistributions in binary form must reproduce the above
//    copyright notice, this list of conditions and the following
//    disclaimer in the documentation and/or other materials provided
//    with the distribution.
//
//    Neither the name of ATI Research, Inc. nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
//THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
//LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
//FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
//COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
//BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
//LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
//CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
//LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//POSSIBILITY OF SUCH DAMAGE.
//

#ifndef HLSL_CROSS_COMPILER_H
#define HLSL_CROSS_COMPILER_H


#include "../Include/Common.h"

#include "glslFunction.h"
#include "glslStruct.h"

class HlslLinker;

class HlslCrossCompiler
{
public:   
   HlslCrossCompiler(EShLanguage l);
   ~HlslCrossCompiler();

   EShLanguage getLanguage() const { return language; }
   TInfoSink& getInfoSink() { return infoSink; }

   void TransformAST (TIntermNode* root);
   void ProduceGLSL (TIntermNode* root);
   bool IsASTTransformed() const { return m_ASTTransformed; }
   bool IsGlslProduced() const { return m_GlslProduced; }

   HlslLinker* GetLinker() { return linker; }

private:
	EShLanguage language;
	bool m_ASTTransformed;
	bool m_GlslProduced;

public:
	HlslLinker* linker;
   TInfoSink infoSink;
   std::vector<GlslFunction*> functionList;
   std::vector<GlslStruct*> structList;
};

#endif //HLSL_CROSS_COMPILER_H
